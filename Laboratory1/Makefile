# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Папки
SRC_DIR = src
OBJ_DIR = src
BIN_DIR = bin

# Файлы
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = $(BIN_DIR)/imageB_exec

# Сборка всех .cpp файлов в .o и линковка
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Правило компиляции для .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
