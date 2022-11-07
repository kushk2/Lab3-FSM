module f1seq(
    input logic en,
    input logic rst,
    input logic clk,

    output logic [7:0] dout
);

    typedef enum {S0, S1, S2, S3, S4, S5, S6, S7, S8} mystate;
    mystate currentstate, nextstate;

    //state registers

    always_ff @(posedge rst, posedge en) begin
        if (rst) currentstate <= S0;
        else if (en) currentstate <= nextstate;
    end

    //nextstate logic

    always_comb 
        case(currentstate)
            S0: if(en == 1) nextstate = S1;
                //else nextstate = currentstate;
            S1: if(en == 1) nextstate = S2;
                //else nextstate = currentstate;
            S2: if(en == 1) nextstate = S3;
                //else nextstate = currentstate;
            S3: if(en == 1) nextstate = S4;
                //else nextstate = currentstate;
            S4: if(en == 1) nextstate = S5;
                //else nextstate = currentstate;
            S5: if(en == 1) nextstate = S6;
                //else nextstate = currentstate;
            S6: if(en == 1) nextstate = S7;
                //else nextstate = currentstate;
            S7: if(en == 1) nextstate = S8;
                //else nextstate = currentstate;
            S8: if(en == 1) nextstate = S0;
                //else nextstate = currentstate;

            default: nextstate = S0;

        endcase   

    //output logic

    always_comb
        case(currentstate)
            S0: dout = 8'0;
            S1: dout = 8'b1;
            S2: dout = 8'b11;
            S3: dout = 8'b111;
            S4: dout = 8'b1111;
            S5: dout = 8'b11111;
            S6: dout = 8'b111111;
            S7: dout = 8'b1111111;
            S8: dout = 8'b11111111;

            default: dout = 8'b0;

        endcase

endmodule
