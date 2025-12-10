#pragma once

#include <string>
#include "BankAccount.h"

// Plain data structure holding account fields (no I/O)
struct AccountData {
    std::string status;
    std::string name;
    std::string surname;
    std::string email;
    std::string phone;
    std::string country;
    std::string town;
    std::string homeAddress;
    unsigned int idno = 0;
    int age = 0;
    double initialDeposit = 0.0;
};

enum class CreateAccountResult {
    Ok = 0,
    Underage,
    InvalidInput,
    IOError
};

// Business-logic function: create an account from provided data without performing console I/O.
CreateAccountResult createAccountFromData(const AccountData& data, BankAccount& out);
