/**
 * @file calculator.cpp
 * @brief the base of the calculator system
 * @author SegCoreDrakon
 * @date 2025-03-31
 * @version 0.2.7
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

#include "../include/calculator.hpp"
#include "../include/calculator_system.hpp"
#include "../include/save_system.hpp"
#include "../include/terminal_ui.hpp"


UI UI;
CalculatorSystem calc_sys;

Calculator::Calculator() {};
Calculator::~Calculator() {};

double Calculator::m_division(double val1,  double val2) {
    if (val1 == 0 || val2 == 0) {
        std::cout << "cannot divide by 0, abording..." << std::endl;
        return 0;
    } else {
        return val1 / val2;
    }
}
double Calculator::m_addition(double val1,  double val2) { return val1 + val2; }
double Calculator::m_subtraction(double val1,  double val2) { return val1 - val2; }
double Calculator::m_multiplication(double val1,  double val2) { return val1 * val2; }

void Calculator::operation() {
    UI.menu_display();
    UI.move(2, 13, true, false);

    m_handle_choice();
}

void Calculator::m_set_result() {
    UI.move(1, 3, false, false);

    std::cout << "result  | " << m_result;
    std::cout.flush();

    history(m_result,  m_operation_type(m_oprt_type));
    sleep_timer(3);
    UI.clear();
    operation();
}

void Calculator::m_input_number() {
    double number1, number2;

    UI.number_display();
    UI.move(6, 2, true, false);

    std::cout << "number 1 | ";
    std::cin >> number1;

    UI.move(1, 2, false, false);

    std::cout << "number 2 | ";
    std::cin >> number2;

    m_number1 = static_cast<float>(number1);
    m_number2 = static_cast<float>(number2);

    std::cin.clear();
    std::cin.ignore(9999, '\n');
}

void Calculator::m_handle_choice() {
    int oprt;

    std::cin >> oprt;

    m_oprt_type = oprt;

    do {
        switch (int(oprt)) {
            case 1:
                result(m_addition(m_number1, m_number2));
                return;

            case 2:
                result(m_subtraction(m_number1, m_number2));
                return;

            case 3:
                result(m_multiplication(m_number1, m_number2));
                return;

            case 4:
                result(m_division(m_number1, m_number2));
                return;

            case 5:
                calc_sys.check_logs();
                m_handle_choice();
                break;

            case 6:
                calc_sys.delete_logs();
                operation();
                break;

            case 7:
                calc_sys.leave_program();

            default:
                calc_sys.uknown_option();

                // to avoid infinite loop
                // when an uncorrect numbed is provided
                oprt = 0;
                if (int(oprt) == 0) {
                    UI.clear();
                    std::cin.clear();
                    UI.menu_display();
                    UI.move(2, 13, true, false);
                    m_handle_choice();
                }

        } // end of switch condition

    } while (true);
}

/**
 * @brief return the return type for history
 * @see m_set_result()
 */
std::string Calculator::m_operation_type(int oprt_type) {
    switch (oprt_type) {
    case 1:
        return "addition";
        break;

    case 2:
        return "substraction";
        break;

    case 3:
        return "multiplication";
        break;

    case 4:
        return "division";
        break;

    default:
        return "ERROR";
        break;
    }
}

// used for making timer without write thread function
void sleep_timer(int time) {
    std::this_thread::sleep_for(std::chrono::seconds(time));
}

void Calculator::result(double computation) {
    m_input_number();
    m_result = static_cast<float>(computation);
    m_set_result();
}
