#include "InvestmentAccount.h"
#include <iostream>

InvestmentAccount::InvestmentAccount(int number, double bal, std::string owner, std::string type,
                                     double mainBal, double investBal, double rate)
    : BankAccount(number, bal, owner, type), mainBalance(mainBal), investmentBalance(investBal), growthRate(rate) {}

void InvestmentAccount::applyGrowth() {
    investmentBalance += investmentBalance * growthRate;
}

void InvestmentAccount::transferToInvestment(double amount) {
    if (amount <= mainBalance) {
        mainBalance -= amount;
        investmentBalance += amount;
    }
}

void InvestmentAccount::withdrawFromInvestment(double amount) {
    if (amount <= investmentBalance) investmentBalance -= amount;
}

void InvestmentAccount::displaySummary() {
    std::cout << "Main Balance: " << mainBalance
              << "\nInvestment Balance: " << investmentBalance
              << "\nGrowth Rate: " << growthRate << std::endl;
}
