clang++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib \
-o sim hello.cpp -lsystemc -lm
./sim
