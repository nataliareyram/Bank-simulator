#ifndef INVESTMENTACCOUNT_H
#define INVESTMENTACCOUNT_H

#include "BankAccount.h"

class InvestmentAccount : public BankAccount {
private:
    double investmentBalance;
    double growthRate;

public:
    InvestmentAccount(std::string accountNumber, double balance, std::string ownerName, std::string accountType, 
                      double investmentBalance, double growthRate);

    double getInvestmentBalance() const;
    void setInvestmentBalance(double investmentBalance);

    double getGrowthRate() const;
    void setGrowthRate(double growthRate);

    void applyGrowth();
    void transferToInvestment(double amount);
    void withdrawFromInvestment(double amount);
};

#endif
