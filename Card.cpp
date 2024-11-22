#include "Card.h"

Card::Card(const std::string& credit, const std::string& debit)
    : credit(credit), debit(debit) {}

std::string Card::getCredit() const {
    return credit;
}

void Card::setCredit(const std::string& credit) {
    this->credit = credit;
}

std::string Card::getDebit() const {
    return debit;
}

void Card::setDebit(const std::string& debit) {
    this->debit = debit;
}
