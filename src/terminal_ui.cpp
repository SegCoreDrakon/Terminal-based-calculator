/**
 * @file terminal_ui.cpp
 * @brief UI system for display ASCII graphic in the terminal
 * @author SegCoreDrakon
 * @date 2025-02-20
 * @version 0.0.8
 */

#include <iostream>
#include <cstdlib>
#include "../include/terminal_ui.hpp"

#include <cstdlib>

UI::UI() {};
UI::~UI() {};

void UI::menu_display() const {
    std::cout << "+========================+" << std::endl;
    std::cout << "|  choose an option      |" << std::endl;
    std::cout << "|  1) addition           |" << std::endl;
    std::cout << "|  2) substraction       |" << std::endl;
    std::cout << "|  3) multiplication     |" << std::endl;
    std::cout << "|  4) division           |" << std::endl;
    std::cout << "|  5) check logs         |" << std::endl;
    std::cout << "|  6) delete logs        |" << std::endl;
    std::cout << "|  7) quit               |" << std::endl;
    std::cout << "+========================+" << std::endl;
    std::cout << "option: ";
}

/**
 * @brief display all the computations logs
 */
void UI::logs_display() const {

    // strings used to write and put inside the data in the log file
    std::string start_data_history = "------------------------"
                                     "[STARTING HISTORY DATA FILE]"
                                     "------------------------\n";
    std::string end_data_history = "--------------------------"
                                   "[ENDING HISTORY DATA FILE]"
                                   "--------------------------\n";

    std::cout << start_data_history << std::endl;
    std::cout << system("cat logs/history.log") << std::endl;
    std::cout << end_data_history << std::endl;
}

void UI::number_display() const {


}
