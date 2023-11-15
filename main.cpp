// Run main
#include "Player.h"
#include <iostream>
#include "helpers.h"
#include <filesystem>
#include "Board.h"
namespace fs = std::filesystem;

using namespace std;

int main() {
    std::cout << "Current Working Directory: " << fs::current_path() << std::endl;
    // Create players
    Player player1("Player 1");
    Player player2("Vermius");
    Board player_board(player1);
    Board enemy_board(player2);

    // Read and populate player decks
    readDeck("player_deck.txt", player1);
    readDeck("vermius_deck.txt", player2);

    // Prepare for game run
    cout << "Holding . . ." << endl;
    system("pause");
    system("cls");

    // Create the game board
    Board gameBoard(player1);
    Board enemyBoard(player2);

    gameBoard.displayBoard();

    // Simulate a turn
    bool endTurn = false;
    while (!endTurn) {
        // Display the menu
        std::cout << "Your turn! What will you do?" << std::endl;
        std::cout << "1.- Place cards\n"
                  << "2.- Check the board\n"
                  << "3.- Listen to Vermius\n"
                  << "4.- Attack\n"
                  << "5.- End turn\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Simulate placing cards on the board
                cout << "Choose a card of your hand to place down!\n";

                // TODO: Add logic to get the card chosen by the player from their hand
                // and place it on the board, also removing it from their hand.

                // Add cards to the board
                player_board.addCardToBoard(card1);
                player_board.displayBoard();

                break;
            }
            case 2:
                // Display the current state of the board
                cout << "Vermiu's board: ";
                enemy_board.displayBoard();
                cout << player1.getName() << "'s board: ";
                player_board.displayBoard();
                system("pause");  // Pause to give the user time to read the board information
                break;
            case 3:
                // Add logic for listening to Vermius
                cout << player2.getName() << ": " << "I do not intend to give you ANY advice\nPrepare to meet my unfiltered wrath!.";
                break;
            case 4:
                // TODO: Add logic for attacking
                // Example:
                // player1.attack(player_board, enemy_board);
                endTurn = true;  // Set endTurn to true to exit the loop
                break;
            case 5:
                // End the turn
                endTurn = true;  // Set endTurn to true to exit the loop
                break;
            default:
                std::cout << "Invalid choice. Please choose a valid option.\n";
                break;
        }
    }
    return 0;
}