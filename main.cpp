#include <iostream>
#include <string>
#include "Bank.h"
#include "Customer.h"
#include "BankAccount.h"
#include "InvestmentAccount.h"
#include "Card.h"
//main function definition with user interaction to define the initial values required to create the bank in which the transactions will be performed.
int main() {
    std::string bankName, location;
    std::cout << "=== Create bank ===\n";
    std::cout << "Enter the bank's name: ";
    std::getline(std::cin, bankName);
    std::cout << "Enter the bank's location: ";
    std::getline(std::cin, location);

    // The values given will be assigned to the Bank constructor.
    Bank bank(bankName, location);

    // User interaction to obtain the Customer's information.
    std::string customerID, name;
    int phoneNumber;
    std::cout << "\n=== Create a client ===\n";
    std::cout << "Enter client ID: ";
    std::getline(std::cin, customerID);
    std::cout << "Enter client's name: ";
    std::getline(std::cin, name);
    std::cout << "Enter client's phone number: ";
    std::cin >> phoneNumber;
    std::cin.ignore(); 

    // User interaction to create bank account.
    std::string accountNumber, accountType;
    double balance;
    std::cout << "\n=== Create a bank account ===\n";
    std::cout << "Enter account number: ";
    std::getline(std::cin, accountNumber);
    std::cout << "Enter account type (Savings/Checking): ";
    std::getline(std::cin, accountType);
    std::cout << "Enter initial balance: ";
    std::cin >> balance;

    BankAccount bankAcc(accountNumber, balance, name, accountType);

    // User interaction to create investment account.
    std::string investmentAccountNumber;
    double investmentBalance, growthRate;
    std::cout << "\n=== Create an investment account ===\n";
    std::cout << "Enter the investment account number: ";
    std::cin >> investmentAccountNumber;
    std::cout << "Enter the investment account's initial balance: ";
    std::cin >> investmentBalance;
    std::cout << "Enter the growth rate (ex. 0.05 for 5%): ";
    std::cin >> growthRate;

    InvestmentAccount investAcc(investmentAccountNumber, balance, name, "Investment", investmentBalance, growthRate);

    // User interaction to create the card type.
    std::string creditCard, debitCard;
    std::cin.ignore(); 
    std::cout << "\n=== Create Card ===\n";
    std::cout << "Enter your credit card (Visa, MasterCard, American Express, None): ";
    std::getline(std::cin, creditCard);
    std::cout << "Enter your debit card (Visa, MasterCard, American Express, None): ";
    std::getline(std::cin, debitCard);

    Card card(creditCard, debitCard);

    // Client creation using the Customer constructor
    Customer customer(customerID, name, phoneNumber, bankAcc, investAcc, card);
    bank.addCustomer(customer);

    // Task menu
    int option;
    do {
        std::cout << "\n=== Task menu ===\n";
        std::cout << "1. Deposit to main account\n";
        std::cout << "2. Withdraw from main account\n";
        std::cout << "3. Transfer to Investment Account\n";
        std::cout << "4. Apply Growth Rate to Investment Balance\n";
        std::cout << "5. Get Client Information\n";
        std::cout << "6. Leave\n";
        std::cout << "Select an option: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                double depositAmount;
                std::cout << "Enter the desired deposit amount: ";
                std::cin >> depositAmount;
                customer.getBankAccount().deposit(depositAmount);
                std::cout << "Your deposit was successful. New balance: $" << customer.getBankAccount().getBalance() << "\n";
                break;
            }
            case 2: {
                double withdrawAmount;
                std::cout << "Enter the desired withdrawal amount: ";
                std::cin >> withdrawAmount;
                try {
                    customer.getBankAccount().withdraw(withdrawAmount);
                    std::cout << "Your withdrawal was successful. New balance: $" << customer.getBankAccount().getBalance() << "\n";
                } catch (const std::runtime_error& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 3: {
                double transferAmount;
                std::cout << "Enter the amount you wish to transfer to the Investment Account: ";
                std::cin >> transferAmount;
                try {
                    customer.getInvestmentAccount().transferToInvestment(transferAmount);
                    std::cout << "Successful transfer. New Investment Account balance: $" 
                              << customer.getInvestmentAccount().getInvestmentBalance() << "\n";
                } catch (const std::runtime_error& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 4: {
                customer.getInvestmentAccount().applyGrowth();
                std::cout << "Growth Rate applied. New Investment Account balance: $" 
                          << customer.getInvestmentAccount().getInvestmentBalance() << "\n";
                break;
            }
            case 5: {
                std::cout << "\n=== Client Information ===\n";
                std::cout << "ID: " << customer.getCustomerID() << "\n";
                std::cout << "Name: " << customer.getName() << "\n";
                std::cout << "Phone number: " << customer.getPhoneNumber() << "\n";
                std::cout << "Main account balance: $" << customer.getBankAccount().getBalance() << "\n";
                std::cout << "Investment account balance: $" << customer.getInvestmentAccount().getInvestmentBalance() << "\n";
                std::cout << "Credit card: " << customer.getCard().getCredit() << "\n";
                std::cout << "Debit card: " << customer.getCard().getDebit() << "\n";
                break;
            }
            case 6:
                std::cout << "Goodbye! Thank you for using our services.\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }

        if (option != 6) {
            std::cout << "\nBack to Task menu...\n";
        }

    } while (option != 6);

    return 0;
}
