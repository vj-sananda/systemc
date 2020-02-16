CXX=g++
CXXFLAGS=-I${SYSTEMC_HOME}/include 
LDFLAGS=-L${SYSTEMC_HOME}/lib -lsystemc
#LDFLAGS=-lsystemc


.PHONY: clean all

all: refinedmemcpu

clean:
	$(RM) refinedmemcpu

refinedmemcpu: mem_if.hpp memory.cpp cpu.cpp main.cpp cpuadaptor_signals.cpp memadaptor_signals.cpp
	$(CXX) $(CXXFLAGS) -o $@ main.cpp $(LDFLAGS)
