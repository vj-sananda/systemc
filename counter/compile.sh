g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib -lsystemc -lm -o sim \
design.cpp \
testbench.cpp

