/**
 * @file save_system.hpp
 * @brief the header of the save system
 * @author SegCoreDrakon
 * @date 2025-03-31
 * @version 0.0.6
 */

#include <string>

#pragma once
#ifndef SAVE_SYSTEM_HPP
#define SAVE_SYSTEM_HPP

void save_history_count();
void load_history_count();
void history(float val, std::string oprt);

#endif // SAVE_SYSTEM_HPP
