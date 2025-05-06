/**
 * @file calculator_system.cpp
 * @brief the system for all big functions who can not be in the main calculator
 * @author SegCoreDrakon
 * @date 2025-05-2
 * @version 0.0.12
 */

#include <filesystem>
#include <iostream>

#include "../include/calculator_system.hpp"
#include "../include/save_system.hpp"
#include "../include/terminal_ui.hpp"
#include "../include/calculator.hpp"

void CalculatorSystem::delete_logs() const {
    UI UI;
    UI.del_logs_display();
    UI.move(2, 3, true, false);
    std::cout << "removing the logs folder...";
    std::cout.flush();
    std::filesystem::remove_all("logs/");
    sleep_timer(2);
    UI.move(0, 3, false, false);
    UI.move(1, 32, true, true);
    std::cout << "     logs folder removed      ";
    std::cout.flush();
    sleep_timer(2);
    UI.clear();
}

void CalculatorSystem::check_logs() const {
    UI UI;
    UI.clear();
    UI.logs_display();
    sleep_timer(3);
    UI.clear();
    UI.menu_display();
    UI.move(2, 13, true, false);
}

void CalculatorSystem::leave_program() const {
    UI UI;
    UI.move(1, 13, true, false);
    save_history_count();
    UI.empty_display();
    UI.move(2, 2, true, false);
    std::cout << "thank to use my calculator, bye!\n\n";
    std::exit(0);
}

void CalculatorSystem::uknown_option() const {
    UI UI;
    UI.move(1, 13, true, false);
    std::cout << "unknow option!\n";
    sleep_timer(3);
    std::cin.ignore();
    std::cin.clear();
}
