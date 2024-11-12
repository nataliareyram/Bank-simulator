#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    std::string credit;
    std::string debit;

public:
    Card(std::string creditType, std::string debitType);

    std::string getCardType();
};

#endif 
