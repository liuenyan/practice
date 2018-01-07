.PHONY: clean, mrproper
CXX = g++
CXXFLAGS = -g -Wall -std=c++11

all: test_graph

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

test_graph: test_graph.o graph.o depth_first_search.o depth_first_paths.o \
	breadth_first_paths.o
	$(CXX) $(CXXFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f test_graph
