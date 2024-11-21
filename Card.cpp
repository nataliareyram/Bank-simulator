#include "Card.h"
#include <iostream>

Card::Card(const std::string& creditCard, const std::string& debitCard)
    : credit(creditCard), debit(debitCard) {}

std::string Card::getCredit() const {
    return credit;
}

std::string Card::getDebit() const {
    return debit;
}

std::string Card::getCardType() const {
    if (!credit.empty() && !debit.empty()) {
        return "Both Credit and Debit Cards";
    } else if (!credit.empty()) {
        return "Credit Card";
    } else if (!debit.empty()) {
        return "Debit Card";
    } else {
        return "No Card Assigned";
    }
}

void Card::setCredit(const std::string& creditCard) {
    credit = creditCard;
}

void Card::setDebit(const std::string& debitCard) {
    debit = debitCard;
}

std::string Card::displayCardInfo() const {
    std::ostringstream oss;
    oss << "Credit Card: " << (credit.empty() ? "Not assigned" : credit) << "\n"
        << "Debit Card: " << (debit.empty() ? "Not assigned" : debit) << "\n"
        << "Card Type: " << getCardType();
    return oss.str();
}
