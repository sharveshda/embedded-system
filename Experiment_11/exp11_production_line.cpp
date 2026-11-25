#include <systemc>
#include <tlm>
#include <tlm_utils/simple_initiator_socket.h>
#include <tlm_utils/simple_target_socket.h>
#include <iostream>
using namespace sc_core;
using namespace tlm;

struct ProductionLine : sc_module {
    tlm_utils::simple_target_socket<ProductionLine> socket;
    SC_CTOR(ProductionLine) : socket("socket") {
        socket.register_b_transport(this, &ProductionLine::process);
    }
    void process(tlm_generic_payload& trans, sc_time& delay) {
        int* product = reinterpret_cast<int*>(trans.get_data_ptr());
        const char* stages[] = {"Assembly", "Inspection", "Packaging"};
        for (int i = 0; i < 3; ++i) {
            std::cout << "Stage " << (i+1) << " (" << stages[i]
                      << "): product " << *product << std::endl;
            delay += sc_time(10, SC_NS);
        }
        trans.set_response_status(TLM_OK_RESPONSE);
    }
};

struct LineController : sc_module {
    tlm_utils::simple_initiator_socket<LineController> socket;
    SC_CTOR(LineController) : socket("socket") { SC_THREAD(run); }
    void run() {
        int productId = 555;
        tlm_generic_payload tx;
        sc_time delay = SC_ZERO_TIME;
        tx.set_command(TLM_WRITE_COMMAND);
        tx.set_address(0);
        tx.set_data_ptr(reinterpret_cast<unsigned char*>(&productId));
        tx.set_data_length(sizeof(productId));
        tx.set_streaming_width(sizeof(productId));
        tx.set_response_status(TLM_INCOMPLETE_RESPONSE);
        std::cout << "Production line start: product " << productId << std::endl;
        socket->b_transport(tx, delay);
        wait(delay);
        std::cout << "Total annotated processing delay: " << delay << std::endl;
        std::cout << "Production line complete: " << tx.get_response_string() << std::endl;
    }
};

int sc_main(int argc, char* argv[]) {
    LineController controller("controller");
    ProductionLine line("line");
    controller.socket.bind(line.socket);
    sc_start();
    return 0;
}
