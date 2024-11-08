#ifndef INVESTMENTACCOUNT_H
#define INVESTMENTACCOUNT_H

#include "BankAccount.h"

class InvestmentAccount : public BankAccount {
private:
    double mainBalance;
    double investmentBalance;
    double growthRate;

public:
    InvestmentAccount(int number, double bal, std::string owner, std::string type,
                      double mainBal, double investBal, double rate);

    void applyGrowth();
    void transferToInvestment(double amount);
    void withdrawFromInvestment(double amount);
    void displaySummary();
};

#endif 
