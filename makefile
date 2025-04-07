TARGET = calculator

SRC = src/main.cpp \
      src/calculator.cpp \
      src/save_system.cpp \
      src/terminal_ui.cpp \

CXXFLAG = -Wall \
          -Wextra \
          -Wpedantic \
          -Wshadow \
          -Wconversion \
          -Wsign-conversion \
          -Wnull-dereference \
          -Wdouble-promotion \
          --all-warnings \

GCC = g++

OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

execute: all
	./$(TARGET)

%.o : %.cpp
	$(GCC) $(CXXFLAG) -c $< -o $@

$(TARGET): $(OBJ)
	$(GCC) $(CXXFLAG) $^ -o $@

clean:
	@echo "removing all object files and the executable"
	rm -rf $(TARGET) $(OBJ) src/*.o
