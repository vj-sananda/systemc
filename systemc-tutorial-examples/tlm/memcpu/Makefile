CXX=g++
CXXFLAGS=-I${SYSTEMC_HOME}/include 
LDFLAGS=-L${SYSTEMC_HOME}/lib -lsystemc
#LDFLAGS=-lsystemc


.PHONY: clean all

all: memcpu

clean:
	$(RM) memcpu

memcpu: mem_if.hpp memory.cpp cpu.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o $@ main.cpp $(LDFLAGS)
