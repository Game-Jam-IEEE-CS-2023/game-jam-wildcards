//
// Created by Badi on 11/14/2023.
//

#include "Player.h"

using namespace std;

Player::Player(const std::string& playerName) {
    // Initialize player attributes in the constructor
    name = playerName;
    energyCount = 8; // Starting energy count (by rule, it is 8)
    health = 20; // Starting health (by rule, it is 20)
    // Assuming you have a deck of cards, and you want to initialize it in the constructor
    // You can adjust the initialization based on your actual implementation of the Card class
    deck.push_back(Card("Card1", 2, "Description1", "Type1", 3, 2));
    deck.push_back(Card("Card2", 1, "Description2", "Type2", 2, 1));
    // ... Add more cards to the deck as needed
}

void Player::drawCard() {

    if (!deck.empty()) {
        // Draw the top card from the deck
        Card drawnCard = deck.back();

        // Remove the drawn card from the deck
        deck.pop_back();

        // Add the drawn card to the player's hand
        hand.push_back(drawnCard);
    }
    // You might want to handle the case when the deck is empty
    else {
        throw std::out_of_range("Cannot draw a card. The deck is empty! This is your last stand!");
    }
}
