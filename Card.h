#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    std::string credit;
    std::string debit;

public:
    Card(const std::string& creditCard, const std::string& debitCard);

    std::string getCredit() const;
    std::string getDebit() const;
    std::string getCardType() const;

    void setCredit(const std::string& creditCard);
    void setDebit(const std::string& debitCard);
};

#endif // CARD_H
