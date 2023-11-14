//
// Created by Badi on 11/14/2023.
//

#ifndef WILDCARD_CARD_H
#define WILDCARD_CARD_H
// Let's do this

#include <iostream>
#include <string>
#include <vector>

// Define class Card - (Main building block).
class Card {
private:
    std::string cardName;
    int cardCost;
    std::string cardDesc;
    std::string cardType;

public:
    Card(std::string, int, std::string, std::string);
    int getCardCost();
    std::string getCardDesc();
    std::string getCardType();
    void displayCard();
};

#endif //WILDCARD_CARD_H
