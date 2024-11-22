#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    std::string credit;
    std::string debit;

public:
    Card(const std::string& credit, const std::string& debit);

    std::string getCredit() const;
    void setCredit(const std::string& credit);

    std::string getDebit() const;
    void setDebit(const std::string& debit);
};

#endif // CARD_H
