#ifndef __TB_H__
#define __TB_H__

#include "systemc.h"

SC_MODULE(tb) {

  sc_in<bool> clk ;
  sc_out<bool> rst ;

  sc_out< sc_int<16> > inp ;
  sc_out< bool > inp_vld;
  sc_in< bool > inp_rdy ;

  sc_in< sc_int<16> > outp ;
  sc_in< bool > outp_vld;
  sc_out< bool > outp_rdy;

  FILE *outfp;

  void source();
  void sink();
  void terminate();

  SC_CTOR(tb) {
    SC_THREAD( source);
    sensitive << clk.pos();

    SC_THREAD( sink );
    sensitive << clk.pos();

    SC_THREAD( terminate );
    sensitive << clk.pos();
  }

};

#endif
