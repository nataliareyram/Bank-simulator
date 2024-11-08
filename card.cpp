#include "Card.h"

Card::Card(std::string creditType, std::string debitType)
    : credit(creditType), debit(debitType) {}

std::string Card::getCardType() {
    return "Credit: " + credit + ", Debit: " + debit;
}
