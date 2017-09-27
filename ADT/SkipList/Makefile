.PHONY: clean, mrproper
CXX = g++
CXXFLAGS = -g -Wall -std=c++11

all: test_skiplist

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

test_skiplist: test_skiplist.o
	$(CXX) $(CXXFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f test_skiplist
