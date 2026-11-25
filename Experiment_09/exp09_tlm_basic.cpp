#define SC_INCLUDE_DYNAMIC_PROCESSES
#include <systemc>
#include <tlm>
#include <tlm_utils/simple_initiator_socket.h>
#include <tlm_utils/simple_target_socket.h>
#include <iostream>
using namespace sc_core;
using namespace tlm;

struct Target : sc_module {
    tlm_utils::simple_target_socket<Target> socket;
    SC_CTOR(Target) : socket("socket") {
        socket.register_b_transport(this, &Target::b_transport);
    }
    void b_transport(tlm_generic_payload& trans, sc_time& delay) {
        int* ptr = reinterpret_cast<int*>(trans.get_data_ptr());
        std::cout << "Target received: " << *ptr << std::endl;
        delay += sc_time(10, SC_NS);
        trans.set_response_status(TLM_OK_RESPONSE);
    }
};

struct Initiator : sc_module {
    tlm_utils::simple_initiator_socket<Initiator> socket;
    SC_CTOR(Initiator) : socket("socket") { SC_THREAD(run); }
    void run() {
        int data = 555;
        tlm_generic_payload trans;
        sc_time delay = SC_ZERO_TIME;
        trans.set_command(TLM_WRITE_COMMAND);
        trans.set_address(0);
        trans.set_data_ptr(reinterpret_cast<unsigned char*>(&data));
        trans.set_data_length(sizeof(data));
        trans.set_streaming_width(sizeof(data));
        trans.set_response_status(TLM_INCOMPLETE_RESPONSE);
        std::cout << "Initiator sending: " << data << std::endl;
        socket->b_transport(trans, delay);
        wait(delay);
        std::cout << "Transaction delay: " << delay << std::endl;
        std::cout << "Response: " << trans.get_response_string() << std::endl;
    }
};

int sc_main(int argc, char* argv[]) {
    Initiator initiator("initiator");
    Target target("target");
    initiator.socket.bind(target.socket);
    sc_start();
    return 0;
}
