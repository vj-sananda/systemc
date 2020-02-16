CXX=g++
CXXFLAGS=-I${SYSTEMC_HOME}/include 
LDFLAGS=-L${SYSTEMC_HOME}/lib -lsystemc


.PHONY: clean all

all: buffer

clean:
	$(RM) buffer

buffer: buffer_if.hpp flatbuffer.cpp complexbuffer.cpp bufwriter.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o $@ main.cpp $(LDFLAGS)

