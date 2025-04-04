/**
 * @mainpage terminal calculator documentation
 *
 * @section intro_section Introduction
 * this project is a calculator only in terminal who are able to make an output of 2 inputs with
 * basic computation of a program. The 4 calculations of the calculator are following: addition,
 * substraction, multiplication and division.
 *
 *
 *
 * @section features_section Features
 * - Addition, substraction, multiplication and division
 * - documented code with Doxygen
 * - history file for checking your previous calculations
 *
 * @section usage_section Usage
 * ### **manually:**
 * 1. Compile source file from .cpp to .o with this command "g++ -c cppFile.cpp -o cppFile.o"
 *    and change the "fileName" by the name of the file
 * 2. compile all object file under one executabl program with this command "g++ -o main cppFile.o"
 *    and add every '.o' file you compiled, don't forget to not miss a file or the program won't
 *    compile
 * 3. and execute the program by using "./main" or right click on the executable file
 *
 * ### **with makefile:**
 * 1. use 'make all' to compile without executing it
 * 2. and use 'make execute' to compile + execute the program
 *
 * @section author_section Author
 * this project is developped by SegCoreDrakon
 *
 * @section license_section Licence
 * this project are under licence GPL 3.0.
 */

/**
* @file main.cpp
* @brief the base of the program
* @author SegCoreDrakon
* @date 2025-02-01
* @version 0.2.0
*/

#include "../include/calculator.hpp"
#include "../include/save_system.hpp"
#include <cmath>

int main() {
  Calculator* calc = new Calculator;

  load_history_count();
  calc->operation();

  return 0;
}



