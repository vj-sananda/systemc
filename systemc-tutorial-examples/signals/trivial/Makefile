CXXFLAGS=-I/tools/systemc-2.3.2/include #-O2
LDFLAGS=-L/tools/systemc-2.3.2/lib-macosx -lsystemc

.PHONY: all clean

all: trivial

clean:
	$(RM) trivial

trivial: trivial.cpp
	$(CXX) $(CXXFLAGS) -o $@ trivial.cpp $(LDFLAGS)
