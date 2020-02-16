#include "fir.h"

const sc_uint<8> coef[5] = {18,77,107,77,18};

void fir::fir_main(void) {

  sc_int<16> in_data;

      for (int i=0; i<5; i++) {
        taps[i] = 0;
      }

        inp_rdy.write(0);
        outp_vld.write(0);
        outp.write(0);
        wait();

        while(true) {

          inp_rdy.write(1);
          do {
            wait();
          } while( !inp_vld.read() );
          in_data = inp.read();
          inp_rdy.write(0);

                for (int i=4; i > 0; i--)
                        taps[i] = taps[i-1];
                taps[0] = in_data;

                sc_int<16> tmp = 0;
                for (int i=0; i<5; i++) {
                        tmp += taps[i] * coef[i];
                }

                outp_vld.write(1);
                outp.write(tmp);
                do {
                  wait();
                } while ( !outp_rdy.read() );
                outp_vld.write(0);
        }
}
