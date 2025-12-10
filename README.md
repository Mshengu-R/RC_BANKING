# RC_BANKING
THIS IS A BANKING SYSTEM WHICH IS ABOUT TO BE CREATED USING C++.

- It should be modulised into parts 

- It will be improved for storing data to not store them in plain text but hash them.

- There are features which do not verify with the user but after the user clicked that option it goes straight and make that decision, this also needs modification

- It should be made to only make transactions with the user when registered or logged in.

- I developed this system while not doing computer science or related field
- 
# Risima's Banking System (Bankproject)

# I have built this while as personal projects through self teachings
# And currently not enrolled in Computer Science or related field

Short project created as a CLI demonstration of basic banking operations written in C++.
- There is a main file which runs all these modules(Contain every feature code init) use it to check/review the code instead
- This is because I am still learning how to modulise them perfectly and here on github I am facing a bit of a challenge


What this repo contains
- A command-line banking demo that supports registration/login, account creation, deposit, withdraw, simple payments and purchase operations.
- Small algorithm examples (sorting) used for practice.

How to build (Windows / other platforms with CMake)

1. Create a build directory and run CMake:

```powershell
mkdir build; cd build;
cmake .. -G "NMake Makefiles"   # or "Visual Studio 16 2019" or other generator on Windows
cmake --build .
```

2. Run the produced `bank` executable (or `bank.exe` on Windows).

Running tests

Build will create `test_bank` target. Running it will execute a tiny assert-based test harness:

```
powershell
ctest -V
```

Notes & next steps
- This repo was authored as a learning project. It intentionally stores credentials in plaintext files for demonstration only — do not use this for real data.

- Recommended improvements: split modules (done), add unit tests (basic tests added), replace plaintext password storage with a hashed store, add a proper persistence layer and CI.

If you'd like, I can help make a GitHub Actions workflow to build and run tests on push.
# Banking System

## Features
- Account creation and management
- Login and registreation
- Transactions
- Airtime and data bundle purchases
- Transaction history (Yet to be implimented)
- Multi-network support

## Class Structure
- `BankAccount`: Manages account details and balances
- `User`: Handles user authentication and profiles
- `Transaction`: Records financial operations

## Usage
```cpp
BankAccount account;
createAccount(account);
account.deposit(1000);
```

## Error Codes
- E001: Insufficient funds
- E002: Invalid account number
- E003: Network error (Yet to be implimented)

## Modules
- These classes and functions should be having their own modules(To be implimented)

# User
- While entering details make sure to read the statement correctly

├── include/
│   ├── Bank.h
│   ├── BankAccount.h
│   └── User.h
├── src/
│   ├── Bank.cpp
│   ├── BankAccount.cpp
│   ├── User.cpp
│   └── main.cpp
├── tests/
│   └── BankTests.cpp
└── CMakeLists.txt

# Contact me

