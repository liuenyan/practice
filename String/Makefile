all: test

CXX = g++
CXXFLAGS = -g -Wall
RM = rm -r

test:main.o String.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o:%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) *.o test
