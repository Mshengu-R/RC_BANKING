#pragma once

#include <string>

class BankAccount {
protected:
    std::string username;
    std::string userpassword;

public:
    std::string Status;
    std::string Name;
    std::string Surname;
    std::string Email;
    std::string PhoneNum;
    std::string Country;
    std::string Town;
    std::string HomeAddress;
    unsigned int IDno;
    int Age;
    std::string AccountNumber;
    std::string RecipientAccount;
    double Balance;

    BankAccount();

    std::string setUsername();
    std::string setPassword();
    void RETURN();
    double deposit(double amount);
    double withdraw(double amount);
    int registerUser();
    void loginUser();
    void deleteDet();
};

// Functions that operate on BankAccount / UI
std::string generateAccountNumber();
void createAccount(BankAccount& acc);
void RelatedAccounts();
void BuyingOptions();
void Networks();
void buyAirtime(BankAccount &User);
void buyData(BankAccount &User);
void buyVoiceBundle(BankAccount &User);
void showPurchaseMenu(BankAccount &User);
