#include <iostream>
#include <string>
#include <limits> // For numeric_limits
#include "Bank.h"
#include "Customer.h"
#include "BankAccount.h"
#include "InvestmentAccount.h"
#include "Card.h"

int main() {
    std::string bankName, location;
    std::cout << "=== Create bank ===\n";
    std::cout << "Enter the bank's name: ";
    std::getline(std::cin, bankName);
    std::cout << "Enter the bank's location: ";
    std::getline(std::cin, location);

    Bank bank(bankName, location);

    // Create a client
    std::string customerID, name, phoneNumber;
    std::cout << "\n=== Create a client ===\n";
    std::cout << "Enter client ID: ";
    std::getline(std::cin, customerID);
    std::cout << "Enter client's name: ";
    std::getline(std::cin, name);
    std::cout << "Enter client's phone number (without the first 3 city digits ex. 442): ";
    std::getline(std::cin, phoneNumber);

    // Create bank account
    std::string accountNumber, accountType;
    double balance;
    std::cout << "\n=== Create a bank account ===\n";
    std::cout << "Enter account number: ";
    std::getline(std::cin, accountNumber);
    std::cout << "Enter account type (Savings/Checking): ";
    std::getline(std::cin, accountType);
    std::cout << "Enter initial balance: ";
    while (!(std::cin >> balance)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    BankAccount bankAcc(accountNumber, balance, name, accountType);

    // Create investment account
    std::string investmentAccountNumber;
    double investmentBalance, growthRate;
    std::cout << "\n=== Create an investment account ===\n";
    std::cout << "Enter the investment account number: ";
    std::cin >> investmentAccountNumber;
    std::cout << "Enter the investment account's initial balance: ";
    while (!(std::cin >> investmentBalance)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Enter the growth rate (ex. 0.05 for 5%): ";
    while (!(std::cin >> growthRate)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    InvestmentAccount investAcc(investmentAccountNumber, balance, name, "Investment", investmentBalance, growthRate);

    // Create cards
    std::string creditCard, debitCard;
    std::cin.ignore(); 
    std::cout << "\n=== Create Card ===\n";
    std::cout << "Enter your credit card (Visa, MasterCard, American Express, None): ";
    std::getline(std::cin, creditCard);
    std::cout << "Enter your debit card (Visa, MasterCard, American Express, None): ";
    std::getline(std::cin, debitCard);

    Card card(creditCard, debitCard);

    // Create customer
    Customer customer(customerID, name, phoneNumber, bankAcc, investAcc, card);
    bank.addCustomer(customer);

    // Task menu
    std::string option_str;
    std::getline(std::cin, option_str);
    int option: std::stoi(option_str)
    do {
        std::cout << "\n=== Task menu ===\n";
        std::cout << "1. Deposit to main account\n";
        std::cout << "2. Withdraw from main account\n";
        std::cout << "3. Transfer to Investment Account\n";
        std::cout << "4. Apply Growth Rate to Investment Balance\n";
        std::cout << "5. Get Client Information\n";
        std::cout << "6. Leave\n";
        std::cout << "Select an option: ";
        std::getline(std::cin, option);

        switch (option) {
            case 1: {
                double depositAmount;
                std::cout << "Enter the desired deposit amount: ";
                while (!(std::cin >> depositAmount)) {
                    std::cout << "Invalid input. Please enter a valid number: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                customer.getBankAccount().deposit(depositAmount);
                std::cout << "Your deposit was successful. New balance: $" << customer.getBankAccount().getBalance() << "\n";
                break;
            }
            case 2: {
                double withdrawAmount;
                std::cout << "Enter the desired withdrawal amount: ";
                while (!(std::cin >> withdrawAmount)) {
                    std::cout << "Invalid input. Please enter a valid number: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                try {
                    customer.getBankAccount().withdraw(withdrawAmount);
                    std::cout << "Your withdrawal was successful. New balance: $" << customer.getBankAccount().getBalance() << "\n";
                }catch (const std::runtime_error& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 3: {
                double transferAmount;
                std::cout << "Enter the amount you wish to transfer to the Investment Account: ";
                while (!(std::cin >> transferAmount)) {
                    std::cout << "Invalid input. Please enter a valid number: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                try {
                    customer.getInvestmentAccount().transferToInvestment(transferAmount);
                    std::cout << "Successful transfer. New Investment Account balance: $" << customer.getInvestmentAccount().getInvestmentBalance() << "\n";
                } catch (const std::runtime_error& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 4: {
                customer.getInvestmentAccount().applyGrowth();
                std::cout << "Growth Rate applied. New Investment Account balance: $" << customer.getInvestmentAccount().getInvestmentBalance() << "\n";
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
                std::cout << "Invalid option. Please select a number between 1 and 6.\n";
                break; 
        }
            return 0;

    }while (option >=1 & option <7)
}
//ola me quiero matar odio c++