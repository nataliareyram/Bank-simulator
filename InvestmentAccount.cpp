#include "InvestmentAccount.h"
#include <stdexcept>
//Given that this class inherits from BankAccount, the constructor includes the attributes of the superclass, as well as two other independent class attributes. 
InvestmentAccount::InvestmentAccount(std::string accountNumber, double balance, std::string ownerName, std::string accountType, 
                                     double investmentBalance, double growthRate)
    : BankAccount(accountNumber, balance, ownerName, accountType), 
      investmentBalance(investmentBalance), growthRate(growthRate) {}
//The getters and setters for the two independent class atributes are paired together for an organized program.
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
//This method only performs an operation over the original Investment Account balance, to which it adds the interest rate.
void InvestmentAccount::applyGrowth() {
    investmentBalance += investmentBalance * growthRate;
}
//The first method depends on the main account balance to perform a substraction of a certain amount, to later add that amount to the Investment Account balance.
void InvestmentAccount::transferToInvestment(double amount) {
    if (getBalance() >= amount) {
        setBalance(getBalance() - amount);
        investmentBalance += amount;
    } else {
        throw std::runtime_error("Insufficient funds in main balance");
    }
}
//The second method performs the opposite task to the first method, by substracting a certain amount to the Investment Account balance to then add it to the main balance.
void InvestmentAccount::withdrawFromInvestment(double amount) {
    if (investmentBalance >= amount) {
        investmentBalance -= amount;
    } else {
        throw std::runtime_error("Insufficient funds in investment balance");
    }
}
