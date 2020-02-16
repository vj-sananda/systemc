g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib -o sim main.cpp -lsystemc -lm

./sim