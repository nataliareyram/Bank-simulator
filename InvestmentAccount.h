#ifndef INVESTMENTACCOUNT_H
#define INVESTMENTACCOUNT_H

#include <string>
#include "BankAccount.h"

class InvestmentAccount : public BankAccount {
private:
    double mainBalance;
    double investmentBalance;
    double growthRate;

public:
    InvestmentAccount(const std::string& accNum, double mainBal, double investBal, double growth, 
                      const std::string& owner, const std::string& type);

    double getMainBalance() const;
    double getInvestmentBalance() const;
    double getGrowthRate() const;

    void setMainBalance(double mainBal);
    void setInvestmentBalance(double investBal);
    void setGrowthRate(double growth);

    void applyGrowth();
    void transferToInvestment(double amount); 
    void withdrawFromInvestment(double amount); 
    std::string displaySummary() const; 
};

#endif // INVESTMENTACCOUNT_H
