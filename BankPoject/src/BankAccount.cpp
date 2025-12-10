#include "../include/BankAccount.h"
#include "../include/Bank.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstdio>

BankAccount::BankAccount()
    : IDno(0), Age(0), Balance(0.0) {}

std::string BankAccount::setUsername() {
    do {
        std::cin.clear();
        std::cout << "Enter your username: ";
        std::getline(std::cin, username);
        if (!username.empty()) break;
        std::cout << "\nDo not leave a blank space!\n";
    } while (username.empty());
    std::cout << std::endl;
    return username;
}

std::string BankAccount::setPassword() {
    do {
        std::cout << "Enter your password: ";
        std::getline(std::cin, userpassword);
        if (!userpassword.empty()) break;
        std::cout << "\nDo not leave a blank space!\n";
    } while (userpassword.empty());
    std::cout << std::endl;
    return userpassword;
}

void BankAccount::RETURN() { return; }

double BankAccount::deposit(double amount) {
    if (amount <= 0.0) {
        std::cerr << "Deposit amount must be positive\n";
        return Balance;
    }
    Balance += amount;
    return Balance;
}

double BankAccount::withdraw(double amount) {
    if (amount <= 0.0) {
        std::cerr << "Amount must be positive\n";
        return Balance;
    } else if (amount > Balance) {
        std::cerr << "Insufficient funds\n";
        return Balance;
    }
    Balance -= amount;
    return Balance;
}

int BankAccount::registerUser() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    setUsername();
    setPassword();

    std::string storedPass;
    std::ifstream check("Userpassword.txt");
    if (check.is_open()) {
        std::getline(check, storedPass);
        check.close();
    }

    if (storedPass.empty()) {
        std::ofstream credFile("Userpassword.txt", std::ios::trunc);
        std::ofstream USN("Username.txt", std::ios::trunc);
        if (!credFile || !USN) {
            std::cerr << "Error saving credentials\n";
            return 0;
        }
        credFile << userpassword;
        USN << username;
        return 1;
    } else {
        std::string Y;
        std::cout << "There are details within the database, do you wish to overwrite the data found? \n (Y/N) \n";
        std::getline(std::cin, Y);
        if (Y == "Y" || Y == "y") {
            std::ofstream credFile("Userpassword.txt", std::ios::trunc);
            std::ofstream USN("Username.txt", std::ios::trunc);
            if (!credFile || !USN) {
                std::cerr << "Error saving credentials\n";
                return 0;
            }
            credFile << userpassword;
            USN << username;
            std::cout << "\tYour new details have been registered! \n";
            return 1;
        } else {
            std::cerr << "\tOperation cancelled\n";
            return 0;
        }
    }
}

void BankAccount::loginUser() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string inputUser, inputPass;
    std::string storedUser, storedPass;
    std::ifstream checkUSN("Username.txt");
    if (checkUSN.is_open()) std::getline(checkUSN, storedUser);
    checkUSN.close();
    std::ifstream checkUSP("Userpassword.txt");
    if (checkUSP.is_open()) std::getline(checkUSP, storedPass);
    checkUSP.close();

    while (true) {
        std::cout << "Enter your username: ";
        std::getline(std::cin, inputUser);
        std::cout << "Enter your password: ";
        std::getline(std::cin, inputPass);

        if (inputUser == storedUser && inputPass == storedPass && !storedUser.empty()) {
            std::cout << "Login successful!" << std::endl;
            username = inputUser;
            userpassword = inputPass;
            return;
        } else {
            std::cout << "Invalid username or password. Do you wish to try again? \n1. Yes  2. No  3. Register \nChoose: ";
            int Con = 0;
            if (!(std::cin >> Con)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (Con == 1) { continue; }
            else if (Con == 2) { return; }
            else if (Con == 3) { registerUser();
                std::ifstream ufile("Username.txt"); if (ufile.is_open()) std::getline(ufile, storedUser); ufile.close();
                std::ifstream pfile("Userpassword.txt"); if (pfile.is_open()) std::getline(pfile, storedPass); pfile.close();
            } else { std::cout << "Unknown choice, returning.\n"; return; }
        }
    }
}

void BankAccount::deleteDet() {
    std::cin.clear();
    std::remove("Username.txt");
    std::remove("Userpassword.txt");
    std::remove("bankingdet.txt");
}
