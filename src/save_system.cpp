/**
 * @file save_system.cpp
 * @brief save system for computations
 * @author SegCoreDrakon
 * @date 2025-03-29
 * @version 0.0.4
 */

#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

#include "../include/calculator.hpp"

Calculator calc;

void save_history_count() {
    std::cout << "saving data\n";
    std::ofstream file("logs/his_count.txt", std::ios::trunc);

    if (!std::filesystem::exists("logs/")) {
        std::filesystem::create_directories("logs/");
    }

    if (file) {
        file << calc.his;
    }
    file.close();
}

void load_history_count() {

    std::cout << "loading data\n";
    std::ifstream file("logs/his_count.txt");

    if (!std::filesystem::exists("logs/")) {
        std::filesystem::create_directories("logs/");
    }

    if (file) {
        file >> calc.his;
    }
    file.close();
}

/**
 * @brief write the history and type in a file
 *
 * @warning
 * don't add `..` for the path,
 * else the program will not recognize the logs path anymore
 */
void history(float val, std::string oprt) {

    std::ofstream file("logs/history.log", std::ios::app);

    if (!std::filesystem::exists("logs/")) {
        std::filesystem::create_directories("logs/");
    }

    if (!file) {
        std::cerr << "CAUTION: cannot open the history file\n";
        return;
    }

    file << "--------------------[HISTORY]--------------------\n";
    file << "HIS: " << std::to_string(calc.his) << ", TYPE: " << oprt
         << ", RESULT: " << val << std::endl;
    file << "--------------------[  END  ]--------------------\n";

    file.flush();
    file.close();

    calc.his++;
}


