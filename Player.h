//
// Created by Badi on 11/14/2023.
//

#ifndef WILDCARD_PLAYER_H
#define WILDCARD_PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

// Define class Player (block unit master)
class Player {
private:
    std::string name;
    int energyCount;
    int health;
    std::vector<Card> deck;
    std::vector<Card> hand;
    std::vector<Card> board;
public:
    // Constructor
    Player(const std::string& name);

    // Getters and Setters
    std::string getName() const;
    int getEnergyCount() const;
    int getHealth() const;

    // Function to replenish energy for the next turn
    void replenishEnergy();

    void addCardToDeck(const Card& card) {
        deck.push_back(card);
    };

    //Additional methods
    void displayDeck() const {
        for (Card card : deck) {
            card.displayCard();
            std::cout << "\n";
        }
    }

    // Player actions
    void drawCard();
    void playCard(Card& card);
    void takeDamage(int damage);
    void defend(const Card& attackingCard, const Card& defendingCard);
    Card chooseCardFromHand();

    // Additional methods as needed
};



#endif //WILDCARD_PLAYER_H
