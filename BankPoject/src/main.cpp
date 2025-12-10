#include "../include/Bank.h"
#include "../include/BankAccount.h"

#include <iostream>
#include <fstream>
#include <limits>

int main(){ 
    Bank bank;
    bank.displayWelcome();
    firstOptions(); //Registering user
    int choose;
    if(!(std::cin >> choose)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    BankAccount User; // user instance for this session

    switch(choose){
        case 1:
            std::cin.clear();
            User.loginUser();
            break;
        case 2:
            User.registerUser();
            break;
        default:
            std::cout<<"\n/Invalid input\n";
    }

    int Choice;
    do {
        std::cout<<"\f";
        OptionsDisplayScreen(); //These are the options
        if(!(std::cin>>Choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option. Try again.\n";
            continue;
        }
        std::cout<<"\n";
        
        switch(Choice){
            case 1:
                std::cin.clear(); //Creation of account
                createAccount(User);
                break;

            case 2:{ //DEPOSIT 

                std::cout << "Enter amount to deposit: R";
                double amount;
                std::cin >> amount;
                User.deposit(amount);
                std::cout << "New balance: R" << User.Balance << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            
            case 3:{ //WITHDRAW

                std::cout << "Enter amount to withdraw: R";
                double amount;
                std::cin >> amount;
                User.withdraw(amount);
                std::cout << "New balance: R" << User.Balance << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            }
            case 4:{ //PAYMENT

                std::cout<<"For which account do you wish to pay to: \n"; int bnk;
                RelatedAccounts(); //CALLING THE RELATED BANK FUNCTIONS SO THE USER CAN CHOOSE WHICH TO PAY TO
                std::cout<<" Choose option: ";
                std::cin>>bnk;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                do {
                    std::cout<<"Enter the account number: ";
                    std::getline(std::cin, User.RecipientAccount);
                    if(!User.RecipientAccount.empty()) break;
                    std::cout<<"Please do not leave a blank space!"<<std::endl;
                } while(User.RecipientAccount.empty()); 

                std::cout<<"Enter amount to Pay: R";
                double amount;
                std::cin >> amount;
                User.withdraw(amount);
                std::cout<<"Are you sure you want to pay R"<<amount<<" to "<<User.RecipientAccount<<" (1. Yes \n2.Cancel \n3.Restart) ";
                int R; std::cin>>R; 

                if(R==1){ std::cout << "You have succesfully paid R"<< amount <<" to "<< User.RecipientAccount <<"\n New balance: R" << User.Balance << std::endl; }
                else if(R==2){ OptionsDisplayScreen(); }
                else if(R==3){ return 4; }

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

            case 5: { showPurchaseMenu(User); break; }

            case 6: { 
                std::ifstream credFile("bankingdet.txt"); //TO VIEW THE ACCOUNTS
                std::string userBankingdet; //TO READ THE FILE
                std::cout << "Available accounts:\n";
                if (!credFile.is_open()) {
                    std::cout << "No accounts available or failed to open file." << std::endl;
                } else {
                    while (std::getline(credFile, userBankingdet)) {
                        std::cout << userBankingdet << std::endl;
                    }
                }
                break;
            }

            case 7:{
                 How_to_use_bank();
                break; 

            }

            case 8: {
                std::cout<<"\n\nGOOD DAY! \nMY NAME IS RISIMA CHABALALA ...\n";
                break;
            }

            case 9: {
                std::string C;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr<<"Are you sure you want to exit? \n(Y/N) :";
                std::getline(std::cin, C);
                if(C == "Y" || C == "y"){ std::cout<<"Thank you for using my Bank!\n"; break; }
                else if(C == "N" || C == "n"){ return 0; }
                else{ break; }
                break;
            }

            case 10:{
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr<<"Details succesfully deleted! Thank you for using my Bank!\n";
                User.deleteDet();
                return 0;
            }
            default: std::cout << "Invalid option. Try again. \n"; break;
        }
    } while (Choice!=9 && Choice != 10);  
       
    return 0;
}
