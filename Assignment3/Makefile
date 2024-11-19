# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -I./ -ID:/papersNprojects/google_tests/googletest/googletest/include -pthread
LDFLAGS = -LD:/papersNprojects/google_tests/googletest/build/lib -lgtest -lgtest_main

# Исходные и объектные файлы
SRCS = transformer.cpp autobot.cpp decepticon.cpp neutral.cpp gun.cpp heart.cpp \
       test_transformer.cpp test_autobot.cpp test_decepticon.cpp test_neutral.cpp
OBJS = $(SRCS:.cpp=.o)

# Имя итогового исполняемого файла
TARGET = run_tests

# Сборка всего проекта
all: $(TARGET)

# Линковка исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Компиляция каждого исходного файла в объектный
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Удаление всех временных файлов и результата сборки
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
