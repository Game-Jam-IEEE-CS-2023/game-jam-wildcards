//
// Created by Badi on 11/14/2023.
//

#ifndef WILDCARD_CARDDECK_H
#define WILDCARD_CARDDECK_H
#include <iostream>
#include <vector>
#include "Card.h"

// Define the class CardDeck - (Composition).
class CardDeck {
private:
    std::vector<Card> cards;

public:
    void addCard(const Card& card) {
        cards.push_back(card);
    }

    void displayDeck() {
        for (Card& card : cards) {
            card.displayCard();
            std::cout << "---------------------------------\n";
        }
    }
};

#endif //WILDCARD_CARDDECK_H
