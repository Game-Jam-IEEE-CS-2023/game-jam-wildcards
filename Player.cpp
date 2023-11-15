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
        // Handle the case when the deck is empty
    else {
        cout << "There are no more cards in the deck! This is your last stand!\n";
        return;
    }

    cout << "Deck size after drawing: " << deck.size() << "\n";
}

