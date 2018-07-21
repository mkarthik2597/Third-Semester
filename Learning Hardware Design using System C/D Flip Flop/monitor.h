#include "systemc.h"

SC_MODULE(Monitor)
{
    sc_in<bool> D, Clk, Q, QNeg, TClk;

    void Run()
    {
        bool inD, outQ, outQNeg, expQ, expQNeg, passed;

        if (Clk.read() == true) {
            inD = D.read();
            outQ = Q.read();
            outQNeg = QNeg.read();

            expQ = D.read();
            expQNeg = !expQ;
            passed = (outQ == expQ) && (outQNeg == expQNeg);

            cout << "Time " << sc_time_stamp() << "; "
                 << "Inputs = [ "
                 << "D = " << inD << " ]; "
                 << "Outputs = [ "
                 << "Q = " << outQ << ", "
                 << "QNeg = " << outQNeg << " ]; "
                 << "Result = " << (passed ? "PASSED" : "FAILED") << endl;
        }
    }

    SC_CTOR(Monitor)
    {
        SC_METHOD(Run);
        sensitive << TClk.pos();
    }
};

