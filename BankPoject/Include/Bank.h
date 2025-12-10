#pragma once

#include <string>

class Bank {
public:
    std::string BankName;
    int Year;
    std::string About;

    Bank();
    void displayWelcome() const;
};

// Helper UI displays
void firstOptions();
void How_to_use_bank();
void OptionsDisplayScreen();
