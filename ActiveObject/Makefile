all: testActiveObject

CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra 
RM = rm -r

testActiveObject:main.o CommandEngine.o SleepCommand.o DelayedTyper.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o:%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) *.o testActiveObject
