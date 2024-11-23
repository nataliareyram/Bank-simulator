#ifndef CARD_H
#define CARD_H

#include <string>
//Private attributes for the Card class which define the two types of card available, set as string values.
class Card {
private:
    std::string credit;
    std::string debit;
//Constructor that assigns the future values given by the user to the type of card, followed by the paired getters and setters for each one.
public:
    Card(std::string credit, std::string debit);

    std::string getCredit() const;
    void setCredit(std::string credit);

    std::string getDebit() const;
    void setDebit(std::string debit);
};

#endif
