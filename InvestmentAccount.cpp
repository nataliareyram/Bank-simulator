#include "InvestmentAccount.h"
#include <stdexcept>

InvestmentAccount::InvestmentAccount(std::string accountNumber, double balance, std::string ownerName, std::string accountType, 
                                     double investmentBalance, double growthRate)
    : BankAccount(accountNumber, balance, ownerName, accountType), 
      investmentBalance(investmentBalance), growthRate(growthRate) {}

double InvestmentAccount::getInvestmentBalance() const {
    return investmentBalance;
}

void InvestmentAccount::setInvestmentBalance(double investmentBalance) {
    investmentBalance = investmentBalance;
}

double InvestmentAccount::getGrowthRate() const {
    return growthRate;
}

void InvestmentAccount::setGrowthRate(double growthRate) {
    growthRate = growthRate;
}

void InvestmentAccount::applyGrowth() {
    investmentBalance += investmentBalance * growthRate;
}

void InvestmentAccount::transferToInvestment(double amount) {
    if (getBalance() >= amount) {
        setBalance(getBalance() - amount);
        investmentBalance += amount;
    } else {
        throw std::runtime_error("Insufficient funds in main balance");
    }
}

void InvestmentAccount::withdrawFromInvestment(double amount) {
    if (investmentBalance >= amount) {
        investmentBalance -= amount;
    } else {
        throw std::runtime_error("Insufficient funds in investment balance");
    }
}
