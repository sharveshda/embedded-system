#include <systemc>
#include <iostream>
using namespace sc_core;

SC_MODULE(ClockedProcess) {
    sc_in<bool> clk;
    SC_CTOR(ClockedProcess) {
        SC_THREAD(run);
    }
    void run() {
        while (true) {
            wait(clk.posedge_event());
            std::cout << "Time: " << sc_time_stamp()
                      << " - Clock Triggered" << std::endl;
        }
    }
};

int sc_main(int argc, char* argv[]) {
    sc_clock clk("clk", 1, SC_NS);   // 1 ns period
    ClockedProcess p("process");
    p.clk(clk);
    sc_start(5, SC_NS);
    std::cout << "Final simulation time: " << sc_time_stamp() << std::endl;
    return 0;
}
