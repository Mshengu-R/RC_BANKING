#include "../include/Bank.h"
#include "../include/BankAccount.h"

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <random>
#include <limits>

Bank::Bank() {
    BankName = "Risima's FNB Banking System";
    Year = 2025;
    About = "Created by Risima Chabalala using C++ in 2025.";
}

void Bank::displayWelcome() const {
   std::cout << "\f WELCOME TO \"" << BankName << "\" CREATED IN " << Year << " ---copyright(c) all rights reserved \n "<< std::endl;
    std::cout<<"\n\tDISCLAIMER! \n\tPLEASE NOTE THERE ARE SOME FEATURES WHICH ARE CURRENTLY NOT AVAILABLE/FUNCTIONING WELL. I AM BUSY FIXING THEM.\n";
}

void firstOptions(){
    std::cout<<"\n1. Login\n";
    std::cout<<"2. Register for banking \n";
    std::cout<<"Choose an option: ";
}

void How_to_use_bank(){
    std::cout<<"\n Good day and thank you for using my(Risima) system.\n 1. You have to log in using the stored details.\n2. For now it only stores details for one users thus it is not an API. So somehow somehow you can still make transactions without having a clear account therefore, this is something I have to fix. \n3. This is a command line therefore ARE NO GRAPHICS. \n";
}

void OptionsDisplayScreen(){
    std::cout<<"\n  ______________________________"<<__TIME__<<"__________________________________\n";
    std::cout<<"\n_________________________________-MENU-________________________________________ \n"; 
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t1. Create a bank Account  \t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t2. Deposit   \t\t\t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t3. Withdraw  \t\t\t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t4. Pay            \t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t5. Buy           \t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t6. View accounts \t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t7. How to use our bank  \t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t8. About \t\t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t9. Exit \t\t\t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t10. Exit and clear data \t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n\n";
    std::cout<<"\t\t\tChoose an option: ";
}

// Related accounts list
void RelatedAccounts(){
    std::cout<<"\t1.Capitec\n";
    std::cout<<"\t2.FNB\n";
    std::cout<<"\t3.Nedbank\n";
    std::cout<<"\t4.Standard bank\n";
    std::cout<<"\t5.TymBank\n";
}

void BuyingOptions(){
    std::list<std::string>ThingstoBuy={"1. Bundles", "2. Electricity"};
    for(std::string ThingtoBuy: ThingstoBuy){
        std::cout<<ThingtoBuy<<"\n";
    }
}

void Networks(){
    std::list<std::string>networks={"1. MTN", "2. Vodacom", "3. Telkom", "4. Cell C"};
    for(std::string network : networks){
        std::cout<<network<<"\n";
    }
}

// purchase helpers
void buyAirtime(BankAccount &User) {
    double amount;
    std::cout << "Enter amount of airtime to buy : R";
    if (!(std::cin >> amount)) { 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid amount\n";
        return;
    }
    if (amount <= 0.0) { std::cout << "Amount must be positive\n"; return; }
    if (amount > User.Balance) { std::cout << "Insufficient funds.\n"; return; }
    User.withdraw(amount);
    std::cout << "You have purchased airtime for R" << amount << ". New balance: R" << User.Balance << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void buyData(BankAccount &User) {
    int choice;
    std::cout << "Choose a data bundle:\n";
    std::cout << "1. 100MB - R10\n";
    std::cout << "2. 500MB - R25\n";
    std::cout << "3. 1GB - R40\n";
    std::cout << "Enter your choice: ";
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice\n";
        return;
    }

    double amount = 0;
    switch (choice) {
        case 1: amount = 10; break;
        case 2: amount = 25; break;
        case 3: amount = 40; break;
        default: std::cout << "Invalid choice.\n"; return;
    }

    if (amount > User.Balance) { std::cout << "Insufficient funds.\n"; return; }
    User.withdraw(amount);
    std::cout << "You have purchased the bundle for R" << amount << ". New balance: R" << User.Balance << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void buyVoiceBundle(BankAccount &User) {
    int choice;
    std::cout << "Choose a voice bundle:\n";
    std::cout << "1. 10 minutes - R5\n";
    std::cout << "2. 30 minutes - R12\n";
    std::cout << "3. 60 minutes - R20\n";
    std::cout << "Enter your choice: ";
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice\n";
        return;
    }

    double amount = 0;
    switch (choice) {
        case 1: amount = 5; break;
        case 2: amount = 12; break;
        case 3: amount = 20; break;
        default: std::cout << "Invalid choice.\n"; return;
    }

    if (amount > User.Balance) { std::cout << "Insufficient funds.\n"; return; }
    User.withdraw(amount);
    std::cout << "You have purchased the voice bundle for R" << amount << ". New balance: R" << User.Balance << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showPurchaseMenu(BankAccount &User) {
    int option;
    std::cout << "\n--- Purchase Menu ---\n";
    std::cout << "1. Buy Airtime\n";
    std::cout << "2. Buy Data\n";
    std::cout << "3. Buy Voice Bundle\n";
    std::cout << "Enter your option: ";
    if (!(std::cin >> option)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid option.\n";
        return;
    }

    switch (option) {
        case 1: buyAirtime(User); break;
        case 2: buyData(User); break;
        case 3: buyVoiceBundle(User); break;
        default: std::cout << "Invalid option.\n"; break;
    }
}

// A simple account number generator
std::string generateAccountNumber() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 9);
    std::string accNum;
    accNum.reserve(14);
    for (int i = 0; i < 14; ++i) accNum.push_back(char('0' + dist(gen)));
    return accNum;
}

// createAccount is implemented in BankAccount.cpp in terms of the generateAccountNumber
void createAccount(BankAccount& acc) {
    // forwarding to BankAccount-related flows implemented in BankAccount.cpp
    // For simplicity this function calls into behavior in that file by reading/writing
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // reuse logic from the original file is implemented in BankAccount.cpp
    // Here keep a placeholder to maintain API compatibility.
    std::cout << "Creating account (see BankAccount module)\n";
}
