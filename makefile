TARGET = calculator

SOURCES = src/save_system.cpp \
	  src/terminal_ui.cpp \
	  src/calculator.cpp \
	  src/main.cpp \

HEADERS = include/save_system.hpp \
	  include/terminal_ui.hpp \
	  include/calculator.hpp \
	  include/main.hpp \

CXXFLAG = -Wdouble-promotion \
          -Wnull-dereference \
          -Wsign-conversion \
          --all-warnings \
          -Wconversion \
          -Wpedantic\
          -Wshadow \
          -Wextra \
          -Wall \

GCC = g++

OBJ = $(SOURCES:.cpp=.o)

all: check $(TARGET)

execute: all
	./$(TARGET)

check:
	@echo "------------{ CHECKING SOURCES }------------"
	@sh -c '\
		for f in $(SOURCES); do \
			name=$$(basename $$f); \
			echo -n "checking $$name...  "; \
			sleep 0.15; \
			if [ -e "$$f" ]; then \
				echo "FOUND"; \
			else \
				echo "NOT FOUND"; \
				echo ""; \
				echo "ERROR: file $$name not found in src," \
				     "please check if the file is here. Aborting!"; \
				exit 1; \
			fi; \
		done' || exit $$?

	@echo ""
	@echo "------------{ CHECKING HEADERS }------------"
	@sh -c '\
		for f in $(HEADERS); do \
			name=$$(basename $$f); \
			echo -n "checking header $$name...  "; \
			sleep 0.15; \
			if [ -e "$$f" ]; then \
				echo "FOUND"; \
			else \
				echo "NOT FOUND"; \
				echo ""; \
				echo "ERROR: file $$name not found in include," \
				     "please check if the file is here. Aborting!"; \
				exit 1; \
			fi; \
		done' || exit $$?


%.o : %.cpp
	$(GCC) $(CXXFLAG) -c $< -o $@

$(TARGET): $(OBJ)
	$(GCC) $(CXXFLAG) $^ -o $@

clean:
	@echo "removing all object files and the executable"
	rm -rf $(TARGET) $(OBJ) src/*.o
