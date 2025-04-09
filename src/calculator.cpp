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


UI UI; ///< initialize UI display system for ASCII interface

Calculator::Calculator() {};
Calculator::~Calculator() {};

double Calculator::m_addition(double val1,  double val2) { return val1 + val2; }
double Calculator::m_subtraction(double val1,  double val2) { return val1 - val2; }
double Calculator::m_division(double val1,  double val2) { return val1 / val2; }
double Calculator::m_multiplication(double val1,  double val2) { return val1 * val2; }

void Calculator::operation() {
    UI.menu_display();
    m_handle_choice();
}

void Calculator::m_set_result() {
    std::cout << "\nresult: " << m_result;
    std::cout.flush();

    history(m_result,  m_operation_type(m_oprt_type));
    m_sleep_timer(3);
    system("clear");
    operation();
}

void Calculator::m_input_number() {
    double number1, number2;

    std::cout << "\n";
    std::cout << "choose number 1: ";
    std::cin >> number1;
    std::cout << "choose number 2: ";
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

        if (int(oprt) == 1
            || int(oprt) == 2
            || int(oprt) == 3
            || int(oprt) == 4
            || int(oprt) == 5
            || int(oprt) == 6) {

            switch (int(oprt)) {
            case 1:
                m_input_number();
                m_result = m_addition(m_number1, m_number2);
                m_set_result();
                return;

            case 2:
                m_input_number();
                m_result = m_subtraction(m_number1, m_number2);
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
                m_sleep_timer(3);
                system("clear");
                UI.menu_display();
                m_handle_choice();
                break;

            case 6:
                std::cout << "removing the logs folder...\n";
                std::filesystem::remove_all("logs/");
                std::cout << "logs folder removed\n";
                m_sleep_timer(2);
                std::system("clear");
                operation();
                break;

            default:
                std::cout << "ERROR: cannot found the good calcul method\n";
                break;
            } // end of switch condition

        } else if (int(oprt) == 7) {
            save_history_count();
            std::cout << "thank to use my calculator, bye!";
            std::exit(0);
        } else {
            std::cout << "unknow option!\n";
            oprt = 0;
            m_sleep_timer(3);

            // to avoid infinite loop
            // when an uncorrect numbed is provided
            if (int(oprt) == 0) {
                system("clear");
                std::cin.clear();
                std::cin.ignore(9999, '\n');
                UI.menu_display();
                m_handle_choice();
            }
            continue;
        }

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
