#include "Vlfsr.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#include "vbuddy.cpp"

#define MAXSimCycles  10000 //10k

int main(int argc, char **argv, char **env){
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vlfsr* top = new Vlfsr;
    //init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("lfsr.vcd");

    //init Vbuddy
    if(vbdOpen() !=1) return(-1);
    vbdHeader("Lab3:LSFR Rand");
    vbdSetMode(1);

    //initialize simulation inputs
    top->clk = 1;
    top->rst = 0;
    top->en = 0;

    //run simulation for many clock cycles
    for(i = 0; i < MAXSimCycles; i++){
        //dump variables into VCD file and toggle clock
        for(clk = 0; clk < 2; clk++){
            tfp->dump(2*i+clk); //unit is in ps
            top->clk = !top->clk;
            top->eval ();
        }

        // plot rom output value on VBuddy 
        vbdHex(1, int(top->dout) & 0xF);
        vbdBar(top->dout & 0xFF);
        vbdCycle(i+1);
        // end plot

        //change input stimuli
        top->en = vbdFlag();
        top->rst = (i < 2);
        if(Verilated::gotFinish() || vbdGetkey() == 'q') exit(0);
    }
    vbdClose();
    tfp->close();
    exit(0);
}