#include "tb.h"

void tb::source() {
  //Reset
  inp.write(0);
  inp_vld.write(0);

  rst.write(0);
  rst.write(1);
  wait();
  rst.write(0);
  wait();

  sc_int<16> tmp = 2938 ;

  for (int i=0;i<64;i++) {

     if (i > 23 && i < 29)
       tmp = 256;
     else
       tmp = 0;

    inp_vld.write(1);
    inp.write(tmp);
    do {
      wait();
    } while( !inp_rdy.read() );
    inp_vld.write(0);
  }
}

void tb::sink() {
  sc_int<16> indata;

  char output_file[] = "./output.dat";
  outfp = fopen(output_file, "w");
  if ( outfp == NULL ) {
    printf("Unable to open %s for write\n",output_file );
    exit(1);
  }

  outp_rdy.write(0);

  for (int i=0;i<64 ;i++) {
    outp_rdy.write(1);

    do {
      wait();
    } while( !outp_vld.read() );

    indata = outp.read();
    fprintf(outfp, "%d\n", (int)indata );

    outp_rdy.write(0);

    cout << i << " :\t" << indata.to_double() << endl ;
  }

  fclose(outfp);
  sc_stop();


}
