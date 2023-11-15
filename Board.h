//
// Created by Badi on 11/15/2023.
//

#ifndef WILDCARD_BOARD_H
#define WILDCARD_BOARD_H
#include "player.h"

class Board {
private:
    Player& player;
    std::vector<Card> boardCards;

public:
    // Constructor
    Board(Player& player);

    // Function to check if the board is full
    bool isFull() const;

    // Function to check if the board is empty
    bool isEmpty() const;

    // Function to add a card to the board
    void addCardToBoard(const Card& card);

    // Function to display the current state of the board
    void displayBoard() const;

    // Function to get a reference to the card at a specific position on the board
    Card& getCardAtPosition(int position);

    // Function to remove the card at a specific position on the board
    void removeCardAtPosition(int position);
};

#endif //WILDCARD_BOARD_H
