CXX = g++
CXXFLAGS = -Wall -Wpedantic -Werror -std=c++17 -fsanitize=address

SRC_DIR = src
OBJ_DIR = src

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(filter-out src/main.h, $(SRCS:.cpp=.h))
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = run

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

format:
	astyle -A1 -s4 $(SRCS) $(HEADERS)


clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET) $(OBJ_DIR)/*.orig
