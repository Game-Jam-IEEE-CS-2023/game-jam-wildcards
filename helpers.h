//
// Created by Badi on 11/15/2023.
//

#ifndef WILDCARD_HELPERS_H
#define WILDCARD_HELPERS_H

#include "Card.h"
#include "Player.h"

Card parseCard(const std::string& line);
void readDeck(const std::string& filename, Player& player);

#endif //WILDCARD_HELPERS_H
