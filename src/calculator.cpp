/**
 * @file calculator.cpp
 * @brief the base of the calculator system
 * @author SegCoreDrakon
 * @date 2025-03-31
 * @version 0.2.5
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <filesystem>

#include "../include/calculator.hpp"
#include "../include/save_system.hpp"
#include "../include/terminal_ui.hpp"


UI UI; ///< initialize UI display system for ASCII interface

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
    m_sleep_timer(3);
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
                m_input_number();
                m_result = static_cast<float>(m_addition(m_number1, m_number2));
                m_set_result();
                return;

            case 2:
                m_input_number();
                m_result = static_cast<float>(m_subtraction(m_number1, m_number2));
                m_set_result();
                return;

            case 3:
                m_input_number();
                m_result = static_cast<float>(m_multiplication(m_number1, m_number2));
                m_set_result();
                return;

            case 4:
                m_input_number();
                m_result = static_cast<float>(m_division(m_number1, m_number2));
                m_set_result();
                return;

            case 5:
                UI.clear();
                UI.logs_display();
                m_sleep_timer(3);
                UI.clear();

                UI.menu_display();
                UI.move(2, 13, true, false);
                m_handle_choice();
                break;

            case 6:
                UI.del_logs_display();
                UI.move(2, 3, true, false);
                std::cout << "removing the logs folder...";
                std::cout.flush();
                std::filesystem::remove_all("logs/");
                m_sleep_timer(2);
                UI.move(0, 3, false, false);
                UI.move(1, 32, true, true);
                std::cout << "     logs folder removed      ";
                std::cout.flush();
                m_sleep_timer(2);
                UI.clear();
                operation();
                break;

            case 7:
                UI.move(1, 13, true, false);
                save_history_count();
                UI.empty_display();
                UI.move(2, 2, true, false);
                std::cout << "thank to use my calculator, bye!\n\n";
                std::exit(0);

            default:
                UI.move(1, 13, true, false);
                std::cout << "unknow option!\n";
                oprt = 0;
                m_sleep_timer(3);
                std::cin.ignore();
                std::cin.clear();

                // to avoid infinite loop
                // when an uncorrect numbed is provided
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
void Calculator::m_sleep_timer(int time) {
    std::this_thread::sleep_for(std::chrono::seconds(time));
}
