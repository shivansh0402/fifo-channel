#include"systemc.h"
#include"receiver.cpp"
#include"transmitter.cpp"
using namespace std;

int sc_main(int argc, char* argv[])
{
	sc_clock clk("clock", 10, SC_NS, 0.5);
	sc_fifo<char>fifo1;

	transmitter t1("transmitter");
	t1.clock(clk);
	t1.fifo_out(fifo1);

	receiver r1("receiver");
	r1.clock(clk);
	r1.fifo_in(fifo1);

	sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
	sc_trace(tf, clk, "clock");
	sc_trace(tf, r1.ch, "ch");
	
	sc_start(270, SC_NS);

	sc_close_vcd_trace_file(tf);
	return 0;
}