/**
 * @file calculator_system.hpp
 * @brief the header of the calculator system
 * @author SegCoreDrakon
 * @date 2025-05-2
 * @version 0.0.5
 */

#pragma once
#ifndef CALCULATOR_SYSTEM
#define CALCULATOR_SYSTEM

#include "calculator.hpp"

class CalculatorSystem : private Calculator {
public:
  void delete_logs() const;
  void check_logs() const;
  void leave_program() const;
  void uknown_option() const;
};

#endif // CALCULATOR_SYSTEM

