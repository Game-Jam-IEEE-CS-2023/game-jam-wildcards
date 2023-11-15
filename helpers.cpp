//
// Created by Badi on 11/14/2023.
//

#include "CardDeck.h"
#include "Card.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Card parseCard(const std::string& line) {
    std::stringstream ss(line);
    std::string token;

    std::getline(ss, token, ','); // Name
    std::string name = token;

    std::getline(ss, token, ','); // Cost
    int cost = std::stoi(token);

    std::getline(ss, token, ','); // Description
    std::string desc = token;

    std::getline(ss, token, ','); // Type
    std::string type = token;

    std::getline(ss, token, ','); // Attack
    int atk = std::stoi(token);

    std::getline(ss, token, ','); // Defense
    int def = std::stoi(token);

    return {name, cost, desc, type, atk, def};
}

}
