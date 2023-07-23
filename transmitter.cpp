#include<systemc.h>
using namespace std;

struct transmitter :public sc_module
{
	sc_in<bool>clock;
	sc_port<sc_fifo_out_if<char>> fifo_out;
	void transmit()
	{
		const char* ptr = " hello shivansh how are you";
		while (*ptr)
		{
			fifo_out->write(*ptr++);
			
			wait();
		}
	}
	SC_CTOR(transmitter)
	{
		SC_THREAD(transmit);
		sensitive << clock.pos();
	}
};