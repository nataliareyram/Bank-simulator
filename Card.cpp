#include "Card.h"

Card::Card(std::string credit, std::string debit)
    : credit(credit), debit(debit) {}

std::string Card::getCredit() const {
    return credit;
}

void Card::setCredit(std::string credit) {
    credit = credit;
}

std::string Card::getDebit() const {
    return debit;
}

void Card::setDebit(std::string debit) {
    debit = debit;
}
