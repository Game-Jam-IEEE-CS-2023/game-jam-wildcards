//
// Created by Badi on 11/14/2023.
//

#include "Player.h"

using namespace std;

const int maxEnergyCount = 8;

Player::Player(const std::string& playerName) {
    // Initialize player attributes in the constructor
    name = playerName;
    energyCount = maxEnergyCount; // Starting energy count (by rule, it is 8)
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
}

std::string Player::getName() const {
    return name;
}

Card Player::chooseCardFromHand() {
    // Display the player's hand
    std::cout << "Your hand:\n";
    for (int i = 0; i < hand.size(); ++i) {
        std::cout << i + 1 << ". " << hand[i].getCardName() << " ||| " << "Energy cost: " << "[" << hand[i].getCardCost() << "]" <<"\n";
    }

    // Get the player's choice
    int choice;
    std::cout << "Enter the number of the card you want to play: ";
    std::cin >> choice;

    // Check if the choice is valid
    if (choice >= 1 && choice <= hand.size()) {
        // Get the chosen card
        Card chosenCard = hand[choice - 1];
        // Remove the chosen card from the hand
        hand.erase(hand.begin() + choice - 1);
        return chosenCard;
    } else {
        std::cerr << "Invalid choice. Please choose a valid card.\n";
        // Return a default-constructed card to handle the error
        return {"", 0, "", "", 0, 0};
    }
}

void Player::replenishEnergy() {
    // Replenish energy for the next turn
    energyCount = maxEnergyCount;
}

void Player::takeDamage(int damage) {
    health = health - damage;
    return;
}

