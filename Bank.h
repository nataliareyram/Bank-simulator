#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include "Customer.h"
#include "BankAccount.h"
#include "InvestmentAccount.h"

class Bank {
private:
    std::string bankName;
    std::string location;
    std::vector<Customer> customers;
    std::vector<BankAccount*> bankAccounts;  
    std::vector<InvestmentAccount*> investmentAccounts;  

public:
    Bank(const std::string& name, const std::string& loc);

    std::string getBankName() const;
    std::string getLocation() const;

    void setBankName(const std::string& name);
    void setLocation(const std::string& loc);

    void addCustomer(const Customer& customer);
    void removeCustomer(const std::string& customerID);
    Customer getCustomerInfo(const std::string& customerID) const;

    void addBankAccount(BankAccount* bankAccount);
    void addInvestmentAccount(InvestmentAccount* investmentAccount);
};

#endif // BANK_H
