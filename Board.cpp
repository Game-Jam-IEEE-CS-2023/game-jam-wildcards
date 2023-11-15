//
// Created by Badi on 11/15/2023.
//

#include "Board.h"
#include <iostream>
#include <iomanip>
#include "Card.h"

// Constructor
Board::Board(Player& player) : player(player), boardCards(3, Card("", 0, "", "", 0, 0)) {
    // Initialize the boardCards vector with 3 empty cards
}

// Function to check if the board is full
bool Board::isFull() const {
    // Check if all cells on the board are occupied
    for (Card card : boardCards) {
        if (card.getCardName().empty()) {
            return false;
        }
    }
    return true;
}

// Function to add a card to the board
void Board::addCardToBoard(const Card& card) {
    for (int position = 0; position < 3; ++position) {
        if (boardCards[position].getCardName().empty()) {
            // Place the card on the first available empty position
            boardCards[position] = card;
            return; // Exit the function after placing the card
        }
    }
    // Handle the case when the board is full
    std::cerr << "Cannot place more cards on the board. It is full.\n";
}

// Function to display the current state of the board
void Board::displayBoard() const {
    for (const Card& card : boardCards) {
        std::cout << "[" << std::setw(2) << card.getCardName() << "] ";
    }
    std::cout << "\n";
}
