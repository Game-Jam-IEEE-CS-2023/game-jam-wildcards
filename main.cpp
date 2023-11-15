// Run main
#include "Player.h"
#include <iostream>
#include "helpers.h"
#include <filesystem>
namespace fs = std::filesystem;

using namespace std;

int main() {
    std::cout << "Current Working Directory: " << fs::current_path() << std::endl;
    // Create players
    Player player1("Player 1");
    Player player2("Vermius");

    // Read and populate player decks
    readDeck("player_deck.txt", player1);
    readDeck("vermius_deck.txt", player2);

    // Display initial player decks
    cout << "=== Initial Decks ===" << endl;
    cout << "" <<" Deck:" << endl;
    player1.displayDeck();

    cout << "Vermius's Deck:" << endl;
    player2.displayDeck();

    cout << "Holding . . ." << endl;
    system("pause");
    system("cls");

    return 0;
}