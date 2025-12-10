#include "../include/BankAccount.h"
#include <cassert>
#include <iostream>

int main() {
    BankAccount acc;
    // initial balance should be zero
    assert(acc.Balance == 0.0);

    acc.deposit(100.0);
    assert(acc.Balance == 100.0);

    acc.withdraw(30.0);
    assert(acc.Balance == 70.0);

    // withdraw cannot exceed balance: attempt and ensure balance unchanged
    acc.withdraw(1000.0);
    assert(acc.Balance == 70.0);

    std::cout << "All basic BankAccount tests passed.\n";
    return 0;
}
