#ifndef INVESTMENTACCOUNT_H
#define INVESTMENTACCOUNT_H

#include "BankAccount.h"

class InvestmentAccount : public BankAccount {
private:
    double investmentBalance;
    double growthRate;

public:
    InvestmentAccount(const std::string& accountNumber, double balance, const std::string& ownerName, const std::string& accountType, 
                      double investmentBalance, double growthRate);

    double getInvestmentBalance() const;
    void setInvestmentBalance(double investmentBalance);

    double getGrowthRate() const;
    void setGrowthRate(double growthRate);

    void applyGrowth();
    void transferToInvestment(double amount);
    void withdrawFromInvestment(double amount);
};

#endif // INVESTMENTACCOUNT_H
