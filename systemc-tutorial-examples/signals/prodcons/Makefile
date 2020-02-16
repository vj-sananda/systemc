CXXFLAGS=-I/tools/systemc-2.3.2/include #-O2
LDFLAGS=-L/tools/systemc-2.3.2/lib-macosx -lsystemc

.PHONY: all clean

all: prodcons

clean:
	$(RM) prodcons

prodcons: main.cpp producer.cpp consumer.cpp
	$(CXX) $(CXXFLAGS) -o $@ main.cpp $(LDFLAGS)
