#include <iostream>
#include <string>
#include "Bank.h"
#include "Customer.h"
#include "BankAccount.h"
#include "InvestmentAccount.h"
#include "Card.h"

int main() {
    std::string bankName, location;
    std::cout << "=== Crear banco ===\n";
    std::cout << "Ingrese el nombre del banco: ";
    std::getline(std::cin, bankName);
    std::cout << "Ingrese la ubicación del banco: ";
    std::getline(std::cin, location);

    // Crear banco
    Bank bank(bankName, location);

    // Crear cliente
    std::string customerID, name;
    int phoneNumber;
    std::cout << "\n=== Crear cliente ===\n";
    std::cout << "Ingrese el ID del cliente: ";
    std::getline(std::cin, customerID);
    std::cout << "Ingrese el nombre del cliente: ";
    std::getline(std::cin, name);
    std::cout << "Ingrese el número de teléfono del cliente: ";
    std::cin >> phoneNumber;
    std::cin.ignore(); // Limpiar el buffer de entrada

    // Crear cuenta bancaria
    std::string accountNumber, accountType;
    double balance;
    std::cout << "\n=== Crear cuenta bancaria ===\n";
    std::cout << "Ingrese el número de cuenta: ";
    std::getline(std::cin, accountNumber);
    std::cout << "Ingrese el tipo de cuenta (Savings/Checking): ";
    std::getline(std::cin, accountType);
    std::cout << "Ingrese el saldo inicial: ";
    std::cin >> balance;

    BankAccount bankAcc(accountNumber, balance, name, accountType);

    // Crear cuenta de inversión
    std::string investmentAccountNumber;
    double investmentBalance, growthRate;
    std::cout << "\n=== Crear cuenta de inversión ===\n";
    std::cout << "Ingrese el número de cuenta de inversión: ";
    std::cin >> investmentAccountNumber;
    std::cout << "Ingrese el saldo inicial de la cuenta de inversión: ";
    std::cin >> investmentBalance;
    std::cout << "Ingrese la tasa de crecimiento (ej. 0.05 para 5%): ";
    std::cin >> growthRate;

    InvestmentAccount investAcc(investmentAccountNumber, balance, name, "Investment", investmentBalance, growthRate);

    // Crear tarjeta
    std::string creditCard, debitCard;
    std::cin.ignore(); // Limpiar el buffer de entrada
    std::cout << "\n=== Crear tarjeta ===\n";
    std::cout << "Ingrese la tarjeta de crédito: ";
    std::getline(std::cin, creditCard);
    std::cout << "Ingrese la tarjeta de débito: ";
    std::getline(std::cin, debitCard);

    Card card(creditCard, debitCard);

    // Crear cliente
    Customer customer(customerID, name, phoneNumber, bankAcc, investAcc, card);
    bank.addCustomer(customer);

    // Operaciones con el cliente
    int option;
    do {
        std::cout << "\n=== Menú de operaciones ===\n";
        std::cout << "1. Depositar en cuenta principal\n";
        std::cout << "2. Retirar de cuenta principal\n";
        std::cout << "3. Transferir a cuenta de inversión\n";
        std::cout << "4. Aplicar crecimiento a inversión\n";
        std::cout << "5. Ver detalles de cliente\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                double depositAmount;
                std::cout << "Ingrese la cantidad a depositar: ";
                std::cin >> depositAmount;
                customer.getBankAccount().deposit(depositAmount);
                std::cout << "Depósito exitoso. Nuevo saldo: $" << customer.getBankAccount().getBalance() << "\n";
                break;
            }
            case 2: {
                double withdrawAmount;
                std::cout << "Ingrese la cantidad a retirar: ";
                std::cin >> withdrawAmount;
                try {
                    customer.getBankAccount().withdraw(withdrawAmount);
                    std::cout << "Retiro exitoso. Nuevo saldo: $" << customer.getBankAccount().getBalance() << "\n";
                } catch (const std::runtime_error& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 3: {
                double transferAmount;
                std::cout << "Ingrese la cantidad a transferir a la cuenta de inversión: ";
                std::cin >> transferAmount;
                try {
                    customer.getInvestmentAccount().transferToInvestment(transferAmount);
                    std::cout << "Transferencia exitosa. Nuevo saldo en cuenta de inversión: $" 
                              << customer.getInvestmentAccount().getInvestmentBalance() << "\n";
                } catch (const std::runtime_error& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 4: {
                customer.getInvestmentAccount().applyGrowth();
                std::cout << "Crecimiento aplicado. Nuevo saldo en cuenta de inversión: $" 
                          << customer.getInvestmentAccount().getInvestmentBalance() << "\n";
                break;
            }
            case 5: {
                std::cout << "\n=== Detalles del cliente ===\n";
                std::cout << "ID: " << customer.getCustomerID() << "\n";
                std::cout << "Nombre: " << customer.getName() << "\n";
                std::cout << "Teléfono: " << customer.getPhoneNumber() << "\n";
                std::cout << "Saldo en cuenta principal: $" << customer.getBankAccount().getBalance() << "\n";
                std::cout << "Saldo en cuenta de inversión: $" << customer.getInvestmentAccount().getInvestmentBalance() << "\n";
                std::cout << "Tarjeta de crédito: " << customer.getCard().getCredit() << "\n";
                std::cout << "Tarjeta de débito: " << customer.getCard().getDebit() << "\n";
                break;
            }
            case 6:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (option != 6);

    return 0;
}
