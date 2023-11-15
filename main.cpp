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

    cout << "Holding . . .";
    system("pause");
    system("close");


//    cout << "Player 1's Initial Deck Size: " << player1.getDeckSize() << "\n";
//    cout << "Vermius's Initial Deck Size: " << player2.getDeckSize() << "\n";
    // Draw initial hand
    player1.drawCard();
    player1.drawCard();
    player1.drawCard();
    player1.drawCard();
    player1.drawCard();
    return 0;
}