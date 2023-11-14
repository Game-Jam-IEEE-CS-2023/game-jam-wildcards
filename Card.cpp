//
// Created by Badi on 11/14/2023.
//

// Let's do this

#include <iostream>
#include <string>
#include "Card.h"
#include <iomanip>

using namespace std; // Help

// Define class methods of Card - (Main runs).
Card::Card(string _cardName, int _cardCost, string _cardDesc, string _cardType, int _cardAtk, int _cardDef) {
    cardName = _cardName;
    cardCost = _cardCost;
    cardDesc = _cardDesc;
    cardType = _cardType;
    cardAtk = _cardAtk;
    cardDef = _cardDef;
}

string Card::getCardName() {
    return cardName;
}

int Card::getCardCost() {
    return cardCost;
}

string Card::getCardDesc() {
    return cardDesc;
}

string Card::getCardType() {
    return cardType;
}

void Card::displayCard() {
    const int cardWidth = 40; // Adjustable
    string orbSymbol = "0";

    // Display horizontal line
    cout << setfill('-') << setw(cardWidth) << "\n" << setfill(' ');

    // Display card name
    cout << "[" << setw(cardWidth - 2) << left << cardName << "]" << endl;

    // Display cost
    cout << "Cost: " << setw(cardWidth - 7) << right;
    for (int i = 0; i < getCardCost(); ++i) {
        cout << orbSymbol;
    }
    cout << "|\n";

    // Display type
    cout << "Type: [" << setw(cardWidth - 9) << left << cardType << "]\n";

    // Display description
    cout << "Desc: " << setw(cardWidth - 6) << left << cardDesc << "\n";

    // Display horizontal line
    cout << setfill('-') << setw(cardWidth) << "\n" << setfill(' ');
}

int Card::getCardAtk() {
    return cardAtk;
}

int Card::getCardDef() {
    return cardDef;
}


