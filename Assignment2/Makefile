PROJECT=Assignment2
CXXFLAGS=-c -Wall
CXX=g++
OBJ = main.o functions.o
DEPS=header.h
all: Assignment2a

Assignment2a: main.o functions.o
	$(CXX) main.o functions.o -o Assignment2
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
functions.o: functions.cpp
	$(CXX) $(CXXFLAGS) functions.cpp
clean:
	rm -rf *.o Assignment2 out_example.txt