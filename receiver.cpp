#include<systemc.h>
using namespace std;

struct receiver :public sc_module
{
    sc_in<bool> clock;
    sc_port<sc_fifo_in_if<char>> fifo_in;
    char ch;
    void receive()
    {
        while (true)
        {
            ch='.';
            fifo_in->nb_read(ch);
            cout << ch;
            wait();
        }
    }
    SC_CTOR(receiver)
    {
        SC_THREAD(receive);
        sensitive << clock.pos();
    }

};