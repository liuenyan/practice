all: test.exe

CXX = g++
CXXFLAGS = -g -Wall
RM = rm -rf

test.exe:main.o String.o
	$(CXX) $(CXXFLAGS) -o $@ $^

.o:.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) *.o test.exe
