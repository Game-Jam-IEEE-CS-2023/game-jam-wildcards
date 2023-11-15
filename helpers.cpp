//
// Created by Badi on 11/14/2023.
//

#include "Card.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Player.h"
#include <filesystem>

Card parseCard(const std::string& line) {
    std::stringstream ss(line);
    std::string token;

    // Extract attributes from the line
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

// Function to read a deck file and populate the deck vector
void readDeck(const std::string& filename, Player& player) {
    std::ifstream file("C:/Users/Badir/CLionProjects/WildCard/decks/" + filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            player.addCardToDeck(parseCard(line));
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << filename << " in directory " << std::filesystem::current_path() << "\n";
    }
}
