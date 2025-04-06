#include <cctype>
#include <vector>

#include "../include/error.hpp"

bool check_number(const std::string& input) {
    std::vector<int> valid = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    if (input.empty()) return false;

    for (char c : input) {
        for (int n :valid) {
            if (!(c == n))  {
                return false;
            }
        }
    }
    return true;
}
