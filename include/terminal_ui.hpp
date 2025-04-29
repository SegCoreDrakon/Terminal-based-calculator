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
    void del_logs_display() const;
    void number_display() const;
    void empty_display() const;
    void clear() const;

    /**
     * @brief move the cursor with ANSI escape sequence
     *
     * @details
     * the function use ANSI escape sequence to
     * move the cursor to X and Y point
     *
     * @param X vertical axe for the cursor
     * @param Y horizontal axe for the cursor
     * @param B if true, go up instead of down
     * @param D if true go left instead of right
     */
    void move(int X, int Y, bool B, bool D) const;
};

#endif // TERMINAL_UI_HPP
