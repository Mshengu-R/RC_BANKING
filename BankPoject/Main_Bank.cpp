
//    ------copyright (c) 2025 -------------------------------------------------------------
//    THIS CODE WAS WRITTEN BY RISIMA CHABALALA 2025 
//    ------copyright (c) 2025 ------------------------------------------------------------
//    ALL RIGHTS RESERVED


//IN THE NAME OF JESUS THIS CODE WILL RUN

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <ctime>
#include <algorithm>
#include <list>
#include <iomanip>
#include <map>
#include <cassert>
#include <random>      //  added for modern RNG
#include <limits>      //  added for safe ignore()
#define NEWLINE "\n"

#ifdef _WIN32
#include <conio.h> // used to read password without echo on Windows
#endif 

// NOTE: Modifications summary (high-level)
// - Removed unsafe new/delete for std::string fields.
// - Replaced RETURN() that returned 0 with void RETURN().
// - Reworked register/login file handling to safely read/write and check for file open.
// - Replaced srand/rand with std::random_device + std::mt19937.
// - Added safer input handling (std::cin.ignore with numeric_limits).
// - deleteDet now removes files instead of deleting memory.
// - Added comments where behavior is still placeholder (e.g., functions that act on a local BankAccount).

void firstOptions(){ //THESE ARE THE LOGING AND REGISTERING OPTIONS
    std::cout<< std::setw(70) <<"\n1. Login\n";
    std::cout<< std::setw(70) <<"2. Register for banking \n";
    std::cout<< std::setw(70) <<"Choose an option: ";
} 

void How_to_use_bank(){
    std::cout<<"\n Good day and thank you for using my(Risima) system.\n 1. You have to log in using the stored details.\n2. For now it only stores details for one users thus it is not an API. So somehow somehow you can still make transactions without having a clear account therefore, this is something I have to fix. \n3. This is a command line therefore ARE NO GRAPHICS. \n";
}



void OptionsDisplayScreen(){

    std::cout << std::right;

    std::cout<<"\n  ______________________________"<<__TIME__<<"__________________________________\n";
    std::cout<<"\n_________________________________-MENU-________________________________________ \n"; 
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t1. Create a bank Account  \t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t2. Deposit   \t\t\t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t3. Withdraw  \t\t\t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t4. Pay            \t\t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t5. Buy           \t\t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t6. View accounts \t\t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t7. How to use our bank  \t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t8. About \t\t\t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t9. Exit \t\t\t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n";
    std::cout<<"|\t\t\t10. Exit and clear data \t\t\t\t|\n";
    std::cout<<"|_______________________________________________________________________________|\n\n";
    std::cout<<"Choose an option: ";
}

class Bank{
 public:    
    std::string BankName;
    int Year;
    std::string About;
    
    Bank() { //This constructor will be called automatically when the object is created
        BankName = "Risima's FNB Banking System";
        Year = 2025;
        About = "Created by Risima Chabalala using C++ in 2025.";
    }

    void displayWelcome() const {

       std::cout << std::setw(70) <<"WELCOME TO \"" << BankName << "\" CREATED IN " << Year << " ---copyright(c) all rights reserved \n "<< std::endl;
        std::cout<< std::setw(70)<<"DISCLAIMER! ";
        std::cout << std::endl;
        std::cout << std::setw(70)<<"PLEASE NOTE THERE ARE SOME FEATURES WHICH ARE CURRENTLY NOT AVAILABLE/FUNCTIONING WELL. I AM BUSY FIXING THEM.\n";
   
    }
};

// BankAccount: refactored to remove unsafe pointer usage and to improve API
class BankAccount{
protected: //This for when I wish to make inheritance
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
    unsigned int IDno = 0 ;
    int Age = 0;
    std::string AccountNumber; 
    std::string RecipientAccount;
    double Balance = 0.0;
    
    // setUsername: uses direct std::getline into member; loops until non-empty
    std::string setUsername() {
       
        do { std::cout; std::right;
            std::cin.clear();
            std::cout<< std::setw(70) <<"Enter your username: ";
            std::getline(std::cin, username);
            if(!username.empty()) break;
            std::cout<<"\nDo not leave a blank space!\n";

        } while (username.empty());
        std::cout<<std::endl;

        return username;
    }

    // setPassword: uses direct std::getline into member; loops until non-empty
    std::string setPassword() {

        do { 
            std::cout<< std::setw(70)<<"Enter your password: ";
            std::getline(std::cin, userpassword);
            if(!userpassword.empty()) break;
            std::cout<<"\nDo not leave a blank space!\n";

        } while (userpassword.empty());
        
        std::cout<<std::endl;
        return userpassword;
    }

    // RETURN changed to void: was returning 0 (type mismatch). Use as a no-op placeholder.
    void RETURN() {
        return;
    }

    // deposit/withdraw: pass by value (primitive type). Added validation and clear error messages.
    double deposit(double amount) { 
        if (amount <= 0.0) {
            std::cerr << "Deposit amount must be positive\n";
            return Balance;
        }
        Balance += amount;
        return Balance;
    }

    double withdraw(double amount) {
        if (amount <= 0.0) {
            std::cerr << "Amount must be positive\n";
            return Balance;
        }
        else if (amount > Balance) {
            std::cerr << "Insufficient funds\n";
            return Balance;
        }

        
            Balance -= amount;

        return Balance;

        
    }

    // registerUser: now reads/writes files safely and avoids reading file with while(getline(...)); 
    // NOTE: For practice this stores plaintext credentials — in real projects hash passwords.
    int registerUser() {
        // Ensure any pending numeric input is cleared before using getline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        setUsername();
        setPassword();

        std::string storedPass;
        std::ifstream check("Userpassword.txt");
        if (check.is_open()) {
            // read first line only (we store single credential per demo)
            std::getline(check, storedPass);
            check.close();

        }

        if (storedPass.empty()) {
            // no existing stored password — create new credential files (overwrite)
            std::ofstream credFile("Userpassword.txt", std::ios::trunc);
            std::ofstream USN("Username.txt", std::ios::trunc);
            
            if (!credFile || !USN) {

                std::cerr << std::setw(70) <<"Error saving credentials\n";
                return 0;
            }
            credFile << userpassword;
            USN << username;
            credFile.close();
            USN.close();
            std::cout<< std::setw(70) <<"**You have successfully registered!** \n";
        } 
        
        else {
            std::string Y;
            std::cerr<<std::setw(70) <<"There are details within the database, do you wish to overwrite the data found? \n (Y/N) \n";
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
                credFile.close();
                USN.close();
                std::cout<<"\tYour new details have been registered! \n";
            } 
            
            else {
                std::cerr<<"\tOperation cancelled\n";
                return 0;
            }
        }
        return 1;
    }

    // loginUser: reworked to avoid recursion and handle files safely.
    void loginUser() {

        // Ensure no leftover characters before getline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string inputUser, inputPass;
        std::string storedUser, storedPass;

        // read stored credentials (first line only each file)
        std::ifstream checkUSN("Username.txt");
       
        if (checkUSN.is_open()) std::getline(checkUSN, storedUser);
       
        checkUSN.close();
       
        std::ifstream checkUSP("Userpassword.txt");
       
       
        if (checkUSP.is_open()) std::getline(checkUSP, storedPass);
       
        checkUSP.close();

        while (true) {
            std::cout<< std::setw(70) << "Enter your username: " << std::setw(10);
            std::getline(std::cin, inputUser);
            std::cout << std::setw(70) <<"Enter your password: " << std::setw(10);
            std::getline(std::cin, inputPass);

            if (inputUser == storedUser && inputPass == storedPass && !storedUser.empty()) {
                std::cout << std::setw(50) <<"***Login successful!***" << std::endl;
                username = inputUser;
                userpassword = inputPass;
                return;
            }
            
            
            else {

                std::cerr << std::setw(50) << "Invalid username or password. Do you wish to try again? \n1. Yes  2. No  3. Register \nChoose: ";
                int Con = 0;
                if (!(std::cin >> Con)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
    
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
                if (Con == 1) {

                    continue; // loop again
                } else if (Con == 2) {
                    return; // exit login attempt
                    } 
                
                else if (Con == 3) {
                    registerUser();
                    // after registering, reload stored credentials
                    std::ifstream ufile("Username.txt"); if (ufile.is_open()) std::getline(ufile, storedUser); ufile.close();
                    std::ifstream pfile("Userpassword.txt"); if (pfile.is_open()) std::getline(pfile, storedPass); pfile.close();
    
                } else {
                    std::cout <<std::setw(70) << "Unknown choice, returning.\n";
                    return;
                }
            }
        }
    }

    // deleteDet: instead of deallocating strings, remove credential files safely
    void deleteDet() {

        std::cin.clear();
        // Remove files storing credentials and banking details (if present)

        std::remove("Username.txt");
        std::remove("Userpassword.txt");
        std::remove("bankingdet.txt");

        // Note: return value of std::remove can be checked for errors; omitted for brevity
        
    }

}; //END OF THE BANKACCOUNT CLASS

// generateAccountNumber: replaced with modern RNG (std::mt19937) for better practice
std::string generateAccountNumber() {

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 9);
    std::string accNum;
    accNum.reserve(14);

    for (int i = 0; i < 14; ++i) {
        accNum.push_back(char('0' + dist(gen)));
    }
    return accNum;

}

// createAccount: unchanged logical flow, but uses improved input handling and writes bankingdet.txt safely.
void createAccount(BankAccount& acc) {

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << std::_S_left;
    

    do{ //STATUS
        std::cout<<std::endl << std::setw(50) << "Enter your status (e.g., Mr, Ms)*: "<< std::setw(10); 
        std::getline(std::cin, acc.Status); if(!acc.Status.empty()){break;} std::cout<<"Please do not leave a blank space! \n"; }while(acc.Status.empty());

    do{ //FULLNAMES
        std::cout <<std::setw(50) << "Enter your full names(As they appear in the ID)*: "<< std::setw(10);
        std::getline(std::cin, acc.Name); if(!acc.Name.empty()){break;} std::cout<<"Please do not leave a blank space! \n"; }while(acc.Name.empty());

    do{ //SURNAME
        std::cout <<std::setw(50) << "Enter your surname*: "<< std::setw(10);
        std::getline(std::cin, acc.Surname); if(!acc.Name.empty()){break;} std::cout<<"Please do not leave a blank space! \n";}while(acc.Surname.empty());

    do{ //ENTERS EMAIL
        std::cout <<std::setw(50) <<"Enter your email*: "<< std::setw(10);
        std::getline(std::cin, acc.Email); if(!acc.Email.empty()){break;} std::cout<<"Please do not leave a blank space! \n";}while(acc.Email.empty());

    do{ //USER PHONE NUMBER
        std::cout<<std::setw(50) << "Enter your phone number*: "<<std::setw(10);
        std::getline(std::cin, acc.PhoneNum); if(!acc.PhoneNum.empty()){break;} std::cout<<"Please do not leave a blank space! \n";}while(acc.PhoneNum.empty());

    do{ //ETHNICITY
        std::cout<<std::setw(50) << "Enter your nationality*: "<< std::setw(10);
        std::getline(std::cin, acc.Country); if(!acc.Country.empty()){break;} std::cout<<"Please do not leave a blank space! \n";}while(acc.Country.empty());

    std::string idStr; //THIS VARIABLE FOR THE NEXT LINE
    do{ //ID
    
        std::cout << std::setw(50) << "Enter your ID number*: " << std::setw(10);
        std::getline(std::cin, idStr);
        std::stringstream(idStr) >> acc.IDno; if(!idStr.empty()){break;} std::cout<<"Please do not leave a blank space! \n"; }while(idStr.empty());

    
        std::string ageStr; //THIS VARIABLE FOR THE NEXT LINE
    do{ //USER'S AGE

        std::cout << std::setw(50) << "Enter your age*: " << std::setw(10);
        std::getline(std::cin, ageStr);
        std::stringstream(ageStr) >> acc.Age; if(!ageStr.empty()){break;} std::cout<<"Please do not leave a blank space \n";}while(ageStr.empty());

    do{ //USER'S HOME TOWN

        std::cout <<std::setw(50) << "Enter your home town*: "<< std::setw(10);
        std::getline(std::cin, acc.Town); if(!acc.Town.empty()){break;} std::cout<<"Please do not leave a blank space! \n";}while(acc.Town.empty());

    do{ //HOME ADRESS

        std::cout << std::setw(50) <<"Enter your home address*: "<< std::setw(10);
        std::getline(std::cin, acc.HomeAddress); if(!acc.HomeAddress.empty()){break;} std::cout<<"Please do not leave a blank space! \n";}while(acc.HomeAddress.empty());

        std::cout << std::endl;
        std::cout << std::right;
    std::cout << std::setw(70) <<"Are these details correct? "; std::cout << std::endl; int Very; //VALUE TO VERIFY 
    std::cout << std::setw(50) <<"Name: " << std::setw(10) << acc.Status <<" "<< acc.Name <<" "<< acc.Surname; std::cout << std::endl;
    std::cout << std::setw(50) <<"Email: "<< std::setw(10) << acc.Email; std::cout << std::endl;
    std::cout << std::setw(50) <<"Phone numbers: "<< std::setw(10) << acc.PhoneNum; std::cout << std::endl;
    std::cout << std::setw(50) <<"Age: "<< std::setw(10) <<acc.Age; std::cout << std::endl;
    std::cout << std::setw(50) <<"Nationality: "<< std::setw(10) <<acc.Country; std::cout << std::endl;
    std::cout << std::setw(50) <<"Home town: "<< std::setw(10)<<acc.Town; std::cout << std::endl;
    std::cout << std::setw(50) <<"Home adress: "<< std::setw(10) <<acc.HomeAddress; std::cout << std::endl;
    std::cout << std::setw(50) <<"(Enter 1 if correct! or 0 Exit) Enter your choice: ";

    while(!(std::cin>>Very) ){ //TO MAKE IT ONLY INTEGERES
        //VERIFICATION CONTINUES!
        std::cout<<"\nInvalid input. Try Again!\n";
        std::cin.clear(); //RESET INPUT ERRORS
        std::cin.ignore(1000, '\n'); //remove bad input
    }

    int LegalAge = acc.Age;

    try {

        if(Very==1 && LegalAge >= 18){
            acc.AccountNumber = generateAccountNumber();
            std::cout << "Account created successfully! \nYour account number is: " << acc.AccountNumber << std::endl; //ACCOUNT SUCCESFULLY CREATED

            std:: cout << "Enter amount to deposit: R";
            double amount;
            std::cin >> amount;
            acc.deposit(amount);
            std::cout << "New balance: R" << acc.Balance << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Append banking details to file. Use append to keep records.
            std::ofstream UserDetFile("bankingdet.txt", std::ios::app);
           
            if (UserDetFile.is_open()) {
                
                UserDetFile<<"\nName: " << acc.Status <<" "<< acc.Name <<" "<< acc.Surname <<"\nEmail: "<<acc.Email<<"\nPhone numbers: "<<acc.PhoneNum<<"\nAge: "<<acc.Age<<"\nNationality: "<<acc.Country<<"\nHome town: "<<acc.Town<<"\nHome adress: "<<acc.HomeAddress<<"\nAccount: "<<acc.AccountNumber<<"\nBalance: "<<acc.Balance<<"\n";
                UserDetFile.close();
            } 
            
            else {
                std::cerr << "Warning: failed to save banking details to file.\n";
            }
        }
        
        else if(Very==1 && LegalAge<18){
            std::cout<<"\fDISCLAIMER! \nAccount cannot be created reason: \nUser is younger than 18. \nPlease call or visit your nearest Risima FNB bank for more details! \n\n\f";
            throw 5008;
        } 
        
        else if(Very==0 && LegalAge >= 18){
            std::cout<<"Thank You for using my system!";
            throw 5009;
        
        }
        
        else {

            std::cout<<"/Invalid value! \n";
            throw 5000;
        
        }
    }
    catch(int Err){ std::cerr<<Err<<"An error occured please try again! \n"; }
}

void RelatedAccounts(){
    std::cout<<"\t1.Capitec\n";
    std::cout<<"\t2.FNB\n";
    std::cout<<"\t3.Nedbank\n";
    std::cout<<"\t4.Standard bank\n";
    std::cout<<"\t5.TymBank\n";
}

void BuyingOptions(){
    std::list<std::string>ThingstoBuy={"1. Bundles", "2. Electricity"}; //LIST OF THINGS USER WANTS TO BUY
    for(std::string ThingtoBuy: ThingstoBuy){
        std::cout<<ThingtoBuy<<"\n";
    }
}

void Networks(){ //this is the networks for which the user would want to buy bundles for
    std::list<std::string>networks={"1. MTN", "2. Vodacom", "3. Telkom", "4. Cell C"}; //NETWORK IF USER WANTS TO BUY BUNDLES
    for(std::string network : networks){
        std::cout<<network<<"\n";
    }
}

// NOTE: buyAirtime, buyData, buyVoiceBundle used a local BankAccount User previously.
// That means they operate on a fresh account with zero balance. In real usage they should accept a reference
// to the current user's BankAccount. For now we keep signature but add clear comments.
void buyAirtime(BankAccount &User) { //Airtime
    double amount;
    std::cout << "Enter amount of airtime to buy : R";
    if (!(std::cin >> amount)) { 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid amount\n";
        return;
    }
    if (amount <= 0.0) { std::cout << "Amount must be positive\n"; return; }

    // Check balance before attempting withdraw
    if (amount > User.Balance) {
        std::cout << "Insufficient funds.\n";
        return;
    }
    User.withdraw(amount); // will deduct because we checked balance
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

    if (amount > User.Balance) {
        std::cout << "Insufficient funds.\n";
        return;
    }
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

    if (amount > User.Balance) {
        std::cout << "Insufficient funds.\n";
        return;
    }
    User.withdraw(amount);
    std::cout << "You have purchased the voice bundle for R" << amount << ". New balance: R" << User.Balance << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// showPurchaseMenu now accepts the current user by reference so purchases affect their balance
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
        case 1: 
        buyAirtime(User);
         break;

        case 2: 
        buyData(User);
         break;
        
        case 3: 
        buyVoiceBundle(User); 
        break;
        
        default: std::cout << "Invalid option.\n"; break;
    }
}            
//THESE ARE FOR BUYING THE BUNDLES.

//Main function

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

                std::cout<< std::setw(50)<<"For which account do you wish to pay to: \n"; int bnk;
                RelatedAccounts(); //CALLING THE RELATED BANK FUNCTIONS SO THE USER CAN CHOOSE WHICH TO PAY TO
                std::cout<<" Choose option: ";
                std::cin>>bnk;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                do {

                    std::cout<<std::setw(50) <<"Enter the account number: ";
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
                
                else if(R==3){ 
                
                    return 4; }

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
                std::cout<<"This option is currently under development I am working as fast as I can to make it function. \nSorry for the inconvenience and Thank you for your patience and using my bank!\n";
                
                 How_to_use_bank();
                
                break; 

            }

            case 8: {
                std::cout<<"\n\nGOOD DAY! \nMY NAME IS RISIMA CHABALALA I AM CURRENTLY WORKING ON MY SKILLS FOR SOFTWARE ENGINEERING AND DEVLOPMENT. I CREATED THIS BAKING SYSTEM IN A FORM OF PRACTICE REGARDLESS OF THE NAME \"FNB\" THIS IS AS A RESULT OF ME WILLING TO WORK AT \"...\" AFTER STUDYING FOR BSC IN INFORMATION TECHONLOGY. I STARTED DOING C++ PROGRAMMING IN THE YEAR 2024 AT UNIVERSITY OF VENDA IN ADDITION, I WAS VERY EXCITED TO LEARN THUS I WENT AHEAD TO STUDY PROGRAMMING. I AMENCOUTERING A LOT OF DIFICULITIES IN MY JOURNEY HOWEVER, THAT WILL NOT STOP ME FROM ACHIEVING MY DREAMS AND GOALS. I AM MORE THAN WILLING TO BE A SOFTWARE ENGINEER. \nI WISH GOD COULD BLESS MY JOURNEY! \n\n With Regards,\nChabalala Risima\n";
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
        } //The whole switch function
    } while (Choice!=9 && Choice != 10);  
       
    return 0;
}

//    ------copyright (c) 2025-------------------------------------------------------------
//    THIS CODE WAS WRITTEN BY RISIMA CHABALALA 2025 
//    ------copyright (c) 2025------------------------------------------------------------
//    ALL RIGHTS RESERVED
