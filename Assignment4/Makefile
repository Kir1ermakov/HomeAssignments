TARGET = main
TEST_TARGET = run_test

CXX = g++
CXXFLAGS = -Wall -Wpedantic -Werror -std=c++17 -I/usr/include/gtest -pthread

SRC = main.cpp src/transformer.cpp src/autobot.cpp src/decepticon.cpp src/gun.cpp src/heart.cpp 
HEADERS = $(filter-out main.h, $(SRC:.cpp=.h))
OBJ = $(SRC:.cpp=.o)

TEST_SRC = tests/test_transformer.cpp src/transformer.cpp tests/test_autobot.cpp src/autobot.cpp src/gun.cpp src/heart.cpp

TEST_OBJ = $(TEST_SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ) -lgtest -lgtest_main

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

format:
	astyle -A1 -s4 $(SRC) $(HEADERS) $(TEST_SRC)

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET) *.orig tests/*.orig

test: $(TEST_TARGET)
	./$(TEST_TARGET)