# target, the output of the compilation
TARGET = calculator

# source files
SRC = src/main.cpp \
      src/calculator.cpp \
      src/save_system.cpp \
      src/terminal_ui.cpp \

# flags
CXXFLAGS = -Wall \
          -Wextra \
          -Wpedantic \
          -Wshadow \
          -Wconversion \
          -Wsign-conversion \
          -Wnull-dereference \
          -Wdouble-promotion \
          --all-warnings \

# parameters for user
DEBUG-OPTI =
OPTI =
DEBUG =

# compiler
GCC = g++

# convert all .cpp file in .o file
OBJ = $(SRC:.cpp=.o)

# use debug mode in the compilation
ifeq ($(DEBUG),1)
CXXFLAGS += -g
endif

# use debug + optimization in the compilation
ifeq ($DEBUG-OPTI),1)
CXXFLAGS += -og
endif

# add the number of optimization the user set
# optimization number can be 1, 2, or 3,
# try to avoid the last number for opitmization
# as it is know to be unstable if we use it
#
# the default optimization are set to 2 if
# no value is set
ifdef OPTI
CXXFLAGS += -O$(OPTI)
else
CXXFLAGS += -O2
endif

all: $(TARGET)

execute: all
	./$(TARGET)

%.o : %.cpp
	$(GCC) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(GCC) $(CXXFLAGS) $^ -o $@

clean:
	@echo "removing all object files and the executable"
	rm -rf $(TARGET) $(OBJ) src/*.o
