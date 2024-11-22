#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    std::string credit;
    std::string debit;

public:
    Card(std::string credit, std::string debit);

    std::string getCredit() const;
    void setCredit(std::string credit);

    std::string getDebit() const;
    void setDebit(std::string debit);
};

#endif
