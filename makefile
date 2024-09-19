PROJECT=hello
CXXFLAGS=-c -Wall
CXX=g++
OBJ = main.o hello.o
DEPS=hello.h
all: hello

hello: main.o hello.o
	$(CXX) main.o hello.o -o hello
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
hello.o: hello.cpp
	$(CXX) $(CXXFLAGS) hello.cpp
clean:
	rm -rf *.o hello