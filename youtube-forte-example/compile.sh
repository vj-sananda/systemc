clang++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib -lsystemc -lm -o sim \
fir.cpp \
tb.cpp \
main.cpp
