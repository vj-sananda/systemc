CXX=g++
CXXFLAGS=-I/tools/systemc-2.3.2/include #-O2
LDFLAGS=-L/tools/systemc-2.3.2/lib-macosx -lsystemc
#LDFLAGS=-lsystemc


.PHONY: clean all

all: instlink

clean:
	$(RM) instlink

instlink:  dumbfooexploiter.cpp dumbfooimplementor.cpp fooif.hpp main.cpp
	$(CXX) $(CXXFLAGS) -o $@ main.cpp $(LDFLAGS)

