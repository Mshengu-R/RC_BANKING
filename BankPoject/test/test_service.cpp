#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "../include/BankService.h"
#include "../include/BankAccount.h"

TEST_CASE("createAccountFromData succeeds with valid data") {
    AccountData d;
    d.status = "Mr";
    d.name = "Risima";
    d.surname = "Chabalala";
    d.email = "risimachabalala9@gmail.com";
    d.phone = "0635257847";
    d.country = "SA";
    d.town = "Peninghotsa";
    d.homeAddress = "1 Main St";
    d.idno = 06042504111110;
    d.age = 19;
    d.initialDeposit = 50.0;

    BankAccount acc;
    auto res = createAccountFromData(d, acc);
    REQUIRE(res == CreateAccountResult::Ok);
    REQUIRE(acc.Name == "Alice");
    REQUIRE(acc.Balance == Approx(50.0));
}

TEST_CASE("createAccountFromData rejects underage") {
    AccountData d;
    d.name = "Bob";
    d.surname = "Young";
    d.email = "bob@example.com";
    d.phone = "012";
    d.age = 16;
    BankAccount acc;
    auto res = createAccountFromData(d, acc);
    REQUIRE(res == CreateAccountResult::Underage);
}

TEST_CASE("createAccountFromData rejects missing fields") {
    AccountData d;
    d.age = 25;
    BankAccount acc;
    auto res = createAccountFromData(d, acc);
    REQUIRE(res == CreateAccountResult::InvalidInput);
}
