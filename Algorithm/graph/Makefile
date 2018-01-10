.PHONY: clean, mrproper
CXX = g++
CXXFLAGS = -g -Wall -std=c++11

all: test_graph test_symbol_graph degree_of_seperation

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

test_graph: test_graph.o graph.o depth_first_search.o depth_first_paths.o \
	breadth_first_paths.o connected_components.o cycle.o two_color.o
	$(CXX) $(CXXFLAGS) -o $@ $+

test_symbol_graph: test_symbol_graph.o symbol_graph.o graph.o
	$(CXX) $(CXXFLAGS) -o $@ $+

degree_of_seperation: degree_of_seperation.o symbol_graph.o graph.o \
	breadth_first_paths.o
	$(CXX) $(CXXFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f test_graph test_symbol_graph
