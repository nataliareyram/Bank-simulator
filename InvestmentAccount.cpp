#include "InvestmentAccount.h"
#include <iostream>

InvestmentAccount::InvestmentAccount(double mainBal, double investBal, double growth)
    : mainBalance(mainBal), investmentBalance(investBal), growthRate(growth) {}

double InvestmentAccount::getMainBalance() const {
    return mainBalance;
}

double InvestmentAccount::getInvestmentBalance() const {
    return investmentBalance;
}

double InvestmentAccount::getGrowthRate() const {
    return growthRate;
}

void InvestmentAccount::setMainBalance(double mainBal) {
    mainBalance = mainBal;
}

void InvestmentAccount::setInvestmentBalance(double investBal) {
    investmentBalance = investBal;
}

void InvestmentAccount::setGrowthRate(double growth) {
    growthRate = growth;
}

void InvestmentAccount::applyGrowth() {
    investmentBalance += investmentBalance * (growthRate / 100);
    std::cout << "Growth applied. New Investment Balance: " << investmentBalance << std::endl;
}

void InvestmentAccount::transferToInvestment(double amount) {
    if (amount > 0 && amount <= mainBalance) {
        mainBalance -= amount;
        investmentBalance += amount;
        std::cout << "Transferred " << amount << " to Investment Balance. Main Balance: " << mainBalance 
                  << ", Investment Balance: " << investmentBalance << std::endl;
    } else {
        std::cout << "Invalid transfer amount or insufficient main balance!" << std::endl;
    }
}

void InvestmentAccount::withdrawFromInvestment(double amount) {
    if (amount > 0 && amount <= investmentBalance) {
        investmentBalance -= amount;
        std::cout << "Withdrew " << amount << " from Investment Balance. Remaining Investment Balance: " 
                  << investmentBalance << std::endl;
    } else {
        std::cout << "Invalid withdrawal amount or insufficient investment balance!" << std::endl;
    }
}

std::string InvestmentAccount::displaySummary() const {
    return "Main Balance: " + std::to_string(mainBalance) + "\n" +
           "Investment Balance: " + std::to_string(investmentBalance) + "\n" +
           "Growth Rate: " + std::to_string(growthRate) + "%";
}
