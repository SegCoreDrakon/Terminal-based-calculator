# target, the output of the compilation
TARGET = calculator

# source files
SRC = src/main.cpp \
      src/calculator.cpp \
      src/save_system.cpp \
      src/terminal_ui.cpp \

# flags
CXXFLAG = -Wall \
          -Wextra \
          -Wpedantic \
          -Wshadow \
          -Wconversion \
          -Wsign-conversion \
          -Wnull-dereference \
          -Wdouble-promotion \
          --all-warnings \

# parameters for user
DEBUG-OPTI = ""
OPTIMIZATION = ""
DEBUG = ""

# compiler
GCC = g++

# convert all .cpp file in .o file
OBJ = $(SRC:.cpp=.o)

# use debug mode in the compilation
ifeq ($(DEBUG),1)
CXXFLAG += -g
endif

# use debug + optimization in the compilation
ifeq ($DEBUG-OPTI),1)
CXXFLAG += -Og
endif

# add the number of optimization the user set
# optimization number can be 1, 2, or 3,
# try to avoid the last number for opitmization
# as it is know to be unstable if we use it
CXXFLAG += -O=$(OPTIMIZATION)

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
