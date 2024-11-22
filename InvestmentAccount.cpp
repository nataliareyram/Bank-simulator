#include "InvestmentAccount.h"

InvestmentAccount::InvestmentAccount(const std::string& accountNumber, double balance, const std::string& ownerName, 
                                     const std::string& accountType, double investmentBalance, double growthRate)
    : BankAccount(accountNumber, balance, ownerName, accountType), investmentBalance(investmentBalance), growthRate(growthRate) {}

double InvestmentAccount::getInvestmentBalance() const {
    return investmentBalance;
}

void InvestmentAccount::setInvestmentBalance(double investmentBalance) {
    this->investmentBalance = investmentBalance;
}

double InvestmentAccount::getGrowthRate() const {
    return growthRate;
}

void InvestmentAccount::setGrowthRate(double growthRate) {
    this->growthRate = growthRate;
}

void InvestmentAccount::applyGrowth() {
    investmentBalance += investmentBalance * growthRate;
}

void InvestmentAccount::transferToInvestment(double amount) {
    if (amount <= getBalance()) {
        setBalance(getBalance() - amount);
        investmentBalance += amount;
    }
}

void InvestmentAccount::withdrawFromInvestment(double amount) {
    if (amount <= investmentBalance) {
        investmentBalance -= amount;
    }
}
