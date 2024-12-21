CXX = g++
CXXFLAGS = -Wall -Wpedantic -Werror -std=c++17 -I/usr/include/gtest -pthread

SRC = src/class1.cpp src/class2.cpp src/class3.cpp src/wrapper.cpp 
HEADERS = $(SRC:.cpp=.h)
OBJ = $(SRC:.cpp=.o)

TEST_TARGET = testing

TEST_SRC = tests/class1_test.cpp tests/class2_test.cpp tests/class3_test.cpp tests/wrapperSpecDouble_test.cpp tests/wrapperSpecInt_test.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

$(TEST_TARGET): $(TEST_OBJ) $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ) $(OBJ)   -lgtest -lgtest_main -pthread

tests/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

format:
	astyle -A1 -s4 $(SRC) $(HEADERS) $(TEST_SRC)

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TEST_TARGET) src/*.orig tests/*.orig

test: $(TEST_TARGET)
	./$(TEST_TARGET)
