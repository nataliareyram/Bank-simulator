#include "Card.h"
//The constructor that receives the information defined by their data types.
Card::Card(std::string credit, std::string debit)
    : credit(credit), debit(debit) {}
//Paired getters and setters for the type of cards available, and their return values.
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
