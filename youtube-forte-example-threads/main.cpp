#include "systemc.h"
#include "fir.h"
#include "tb.h"

SC_MODULE(SYSTEM) {
  tb  *tb0;
  fir *fir0;

  sc_signal<bool> rst_sig;
  sc_signal< sc_int<16> > inp_sig;
  sc_signal< sc_int<16> > outp_sig;

  sc_signal< bool > inp_sig_vld;
  sc_signal< bool > inp_sig_rdy;
  sc_signal< bool > outp_sig_vld;
  sc_signal< bool > outp_sig_rdy ;

  sc_clock clk_sig;

  //Clock with 10 ns period
  SC_CTOR(SYSTEM) : clk_sig("clk_sig",10,SC_NS) {
    tb0 = new tb("tb0");
    fir0 = new fir("fir0");

    tb0->clk(clk_sig);
    tb0->rst(rst_sig);
    tb0->inp(inp_sig);
    tb0->outp(outp_sig);
    tb0->inp_vld(inp_sig_vld);
    tb0->inp_rdy(inp_sig_rdy);
    tb0->outp_vld(outp_sig_vld);
    tb0->outp_rdy(outp_sig_rdy);

    fir0->clk(clk_sig);
    fir0->rst(rst_sig);
    fir0->inp(inp_sig);
    fir0->outp(outp_sig);
    fir0->inp_vld(inp_sig_vld);
    fir0->inp_rdy(inp_sig_rdy);
    fir0->outp_vld(outp_sig_vld);
    fir0->outp_rdy(outp_sig_rdy);

  }

  ~SYSTEM(){
    delete tb0;
    delete fir0;
  }
};

SYSTEM *top = NULL;

int sc_main( int argc, char* argv[] ) {

  top = new SYSTEM("top");

  //Turn on VCD tracing
  sc_trace_file* vcd_tf;
  vcd_tf = sc_create_vcd_trace_file("traces");
  sc_trace(vcd_tf, top->clk_sig,"clk");
  sc_trace(vcd_tf, top->rst_sig,"rst");

  sc_trace(vcd_tf, top->inp_sig_vld,"inp_sig_vld");
  sc_trace(vcd_tf, top->inp_sig_rdy,"inp_sig_rdy");
  sc_trace(vcd_tf, top->inp_sig,"inp_sig");
  sc_trace(vcd_tf, top->outp_sig_vld,"outp_vld");
  sc_trace(vcd_tf, top->outp_sig_rdy,"outp_rdy");
  sc_trace(vcd_tf, top->outp_sig,"outp_sig");

  sc_start(1000, SC_NS);

  sc_close_vcd_trace_file(vcd_tf);
  return 0;
}
