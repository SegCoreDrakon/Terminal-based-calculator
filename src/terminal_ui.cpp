/**
 * @file terminal_ui.cpp
 * @brief UI system for display ASCII graphic in the terminal
 * @author SegCoreDrakon
 * @date 2025-02-20
 * @version 0.0.8
 */

#include <iostream>
#include <cstdlib>
#include <cstdlib>

#include "../include/terminal_ui.hpp"

UI::UI() {};
UI::~UI() {};

void UI::menu_display() const {
    std::cout << "+=================================+\n";
    std::cout << "| choose an option                |\n";
    std::cout << "| 1) addition                     |\n";
    std::cout << "| 2) substraction                 |\n";
    std::cout << "| 3) multiplication               |\n";
    std::cout << "| 4) division                     |\n";
    std::cout << "| 5) check logs                   |\n";
    std::cout << "| 6) delete logs                  |\n";
    std::cout << "| 7) quit                         |\n";
    std::cout << "+==========+======================+\n";
    std::cout << "|  option  |                      |\n";
    std::cout << "+==========+======================+\n";
}

/**
 * @brief display all the computations logs
 */
void UI::logs_display() const {

    // strings used to write and put inside the data in the log file
    std::string start_data_history = "=========================="
                                     "[STARTING HISTORY DATA FILE]"
                                     "========================\n";
    std::string end_data_history = "=========================="
                                   "[ENDING HISTORY DATA FILE]"
                                   "==========================\n";

    std::cout << start_data_history << "\n";
    std::cout << system("cat logs/history.log") << "\n";
    std::cout << end_data_history << "\n";
}

void UI::del_logs_display() const {
    std::cout << "+==========+===[ DATA STATUS ]====+\n";
    std::cout << "|                                 |\n";
    std::cout << "+=================================+\n";

}

void UI::number_display() const {
    std::cout << "+==========+=====[ NUMBER 1 ]=====+\n";
    std::cout << "|                                 |\n";
    std::cout << "+==========+=====[ NUMBER 2 ]=====+\n";
    std::cout << "|                                 |\n";
    std::cout << "+==========+=====[  RESULT  ]=====+\n";
    std::cout << "|                                 |\n";
    std::cout << "+==========+======================+\n";
}

void UI::empty_display() const {
    std::cout << "+==========+======================+\n";
    std::cout << "|                                 |\n";
    std::cout << "+=================================+\n";
}

void UI::clear() const {
    std::cout << "\033[2J\033[H";
}

void UI::move(int X, int Y, bool B, bool D) const {
    if (B) {
        std::cout << "\033[" << X << "A";
        if (D) {
            std::cout << "\033[" << Y << "D";
        } else {
            std::cout << "\033[" << Y << "C";
        }
    } else {
        std::cout << "\033[" << X << "B";
        if (D) {
            std::cout << "\033[" << Y << "D";
        } else {
            std::cout << "\033[" << Y << "C";
        }
    }
}
