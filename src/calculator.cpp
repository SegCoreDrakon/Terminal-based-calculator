/**
 * @file calculator.cpp
 * @brief the base of the calculator system
 * @author SegCoreDrakon
 * @date 2025-03-31
 * @version 0.1.0
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

UI UI; // initialize UI display system for ASCII interface

Calculator::Calculator() {};
Calculator::~Calculator() {};

double Calculator::m_addition(double val1,  double val2) { return val1 + val2; }
double Calculator::m_substraction(double val1,  double val2) { return val1 - val2; }
double Calculator::m_division(double val1,  double val2) { return val1 / val2; }
double Calculator::m_multiplication(double val1,  double val2) { return val1 * val2; }

void Calculator::operation() {
    UI.menu_display();
    m_handle_choice();
}

void Calculator::m_set_result() {
    std::cout << "result: " << m_result;

    history(m_result,  m_operation_type(m_oprt_type));
    m_sleep_timer(3);
    UI.clear_screen();
    operation();
}

void Calculator::m_input_number() {
    double number1 = 0;
    double number2 = 0;

    std::cout << "" << std::endl;
    std::cout << "choose number 1: ";
    std::cin >> number1;
    std::cout << "choose number 2: ";
    std::cin >> number2;

    m_number1 = number1;
    m_number2 = number2;

    std::cin.clear();
}

void Calculator::m_handle_choice() {
    int oprt;

    std::cin >> oprt;

    m_oprt_type = oprt;

    do {
        switch (int(oprt)) {
            case 1:
                m_input_number();
                m_result = m_addition(m_number1, m_number2);
                m_set_result();
                return;

            case 2:
                m_input_number();
                m_result = m_substraction(m_number1, m_number2);
                m_set_result();
                return;

            case 3:
                m_input_number();
                m_result = m_multiplication(m_number1, m_number2);
                m_set_result();
                return;

            case 4:
                m_input_number();
                m_result = m_division(m_number1, m_number2);
                m_set_result();
                return;

            case 5:
                UI.logs_display();
                m_sleep_timer(5);
                system("clear");
                UI.menu_display();
                m_handle_choice();
                continue;

            case 6:
                std::cout << "removing the logs folder...\n";
                std::filesystem::remove_all("logs/");
                std::cout << "logs folder removed\n";
                continue;

            case 7:
                save_history_count();
                std::cout << "thank to use my calculator, bye!\n";
                std::exit(0);

            default:
                std::cout << "unknow option!\n";
                m_sleep_timer(3);

                // to avoid infinite loop
                // when an uncorrect numbed is provided
                oprt = 0;
                if (int(oprt) == 0) {
                    std::cin.clear();
                    UI.clear_screen();
                    UI.menu_display();
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
    switch (oprt_type)
    {
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
