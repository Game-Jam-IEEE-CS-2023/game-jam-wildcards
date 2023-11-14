//
// Created by Badi on 11/14/2023.
//

// Let's do this

#include <iostream>
#include <string>
#include "Card.h"

// Define class methods of Card - (Main runs).
Card::Card(string _cardName, int _cardCost, string _cardDesc, string _cardType) {
    cardName = _cardName;
    cardCost = _cardCost;
    cardDesc = _cardDesc;
    cardType = _cardType;
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
    string orbSymbol = "0";
    cout << "[" << cardName << "]" << endl;
    cout << "Cost: ";

    for (int i = 0; i < getCardCost(); ++i) {
        cout << orbSymbol;
    }

    cout << "\nType: [" << cardType << "]\n";
    cout << "\nDesc: " << cardDesc << "\n";
}


