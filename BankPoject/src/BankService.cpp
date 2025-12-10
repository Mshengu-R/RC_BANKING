#include "../include/BankService.h"
#include "../include/BankAccount.h"
#include <fstream>
#include <iostream>

// createAccountFromData: pure logic, no console I/O. Validates and writes to bankingdet.txt.
CreateAccountResult createAccountFromData(const AccountData& data, BankAccount& out) {
    // Basic validation
    if (data.name.empty() || data.surname.empty() || data.email.empty() || data.phone.empty()) {
        return CreateAccountResult::InvalidInput;
    }
    if (data.age < 18) return CreateAccountResult::Underage;

    // Populate the account
    out.Status = data.status;
    out.Name = data.name;
    out.Surname = data.surname;
    out.Email = data.email;
    out.PhoneNum = data.phone;
    out.Country = data.country;
    out.Town = data.town;
    out.HomeAddress = data.homeAddress;
    out.IDno = data.idno;
    out.Age = data.age;
    out.AccountNumber = ""; // caller may set account number via generateAccountNumber()
    out.deposit(data.initialDeposit);

    // Try writing a summary to the bankingdet.txt file
    std::ofstream f("bankingdet.txt", std::ios::app);
    if (!f.is_open()) return CreateAccountResult::IOError;
    f << "\nName: " << out.Status << " " << out.Name << " " << out.Surname << "\n";
    f << "Email: " << out.Email << "\n";
    f << "Phone numbers: " << out.PhoneNum << "\n";
    f << "Age: " << out.Age << "\n";
    f << "Nationality: " << out.Country << "\n";
    f << "Home town: " << out.Town << "\n";
    f << "Home adress: " << out.HomeAddress << "\n";
    f << "Account: " << out.AccountNumber << "\n";
    f << "Balance: " << out.Balance << "\n";
    f.close();
    return CreateAccountResult::Ok;
}
