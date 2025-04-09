/**
 * @file terminal_ui.hpp
 * @brief the header of the UI system
 * @author SegCoreDrakon
 * @date 2025-03-31
 * @version 0.0.14
 */

#pragma once
#ifndef TERMINAL_UI_HPP
#define TERMINAL_UI_HPP

class UI {
public:
    UI();
    ~UI();

    void menu_display() const;
    void logs_display() const;
    void number_display() const;
};

#endif // TERMINAL_UI_HPP
