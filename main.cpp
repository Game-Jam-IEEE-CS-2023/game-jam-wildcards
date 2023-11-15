// Run main
#include "Player.h"
#include <iostream>
#include "helpers.h"
#include <filesystem>
#include "Board.h"
namespace fs = std::filesystem;

using namespace std;

void displayMenu() {
    std::cout << "Your turn! What will you do?" << std::endl;
    std::cout << "1.- Place cards\n"
              << "2.- Check the board\n"
              << "3.- Listen to Vermius\n"
              << "4.- Attack\n"
              << "5.- End turn\n";
}


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
        displayMenu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Simulate placing cards on the board
                std::cout << "Choose a card from your hand to place on the board!\n";
                Card chosenCard = player1.chooseCardFromHand();
                if (!chosenCard.getCardName().empty()) {
                    // Add cards to the board
                    player_board.addCardToBoard(chosenCard);
                    player_board.displayBoard();
                }
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
                // Add logic for attacking
                // Example:
                // player1.attack(player_board, enemy_board);
                if (!player_board.isFull()) {
                    int playerPosition, enemyPosition;

                    // Choose the attacking card from the player's board
                    cout << "Select your attacking card (0, 1, or 2): ";
                    cin >> playerPosition;

                    // If the enemy board is empty, attack the enemy directly
                    if (enemy_board.isEmpty()) {
                        Card& playerCard = player_board.getCardAtPosition(playerPosition);
                        int attackValue = playerCard.getCardAtk();
                        player2.takeDamage(attackValue);
                    } else {
                        // Choose the defending card from Vermius's board
                        cout << "Select Vermius's defending card (0, 1, or 2): ";
                        cin >> enemyPosition;

                        // Validate the positions
                        if (playerPosition >= 0 && playerPosition < 3 && enemyPosition >= 0 && enemyPosition < 3) {
                            Card& playerCard = player_board.getCardAtPosition(playerPosition);
                            Card& enemyCard = enemy_board.getCardAtPosition(enemyPosition);

                            // Compare ATK and DEF stats
                            if (playerCard.getCardAtk() < enemyCard.getCardDef()) {
                                cout << "Vermius's defending card deflects your attack!\n";
                            } else if (playerCard.getCardDef() < enemyCard.getCardAtk()) {
                                cout << "Your attacking card is eliminated!\n";
                                player_board.removeCardAtPosition(playerPosition);
                            } else {
                                // Cards are tied, both are destroyed
                                cout << "Both cards are destroyed in battle!\n";
                                player_board.removeCardAtPosition(playerPosition);
                                enemy_board.removeCardAtPosition(enemyPosition);
                            }
                        } else {
                            cout << "Invalid card positions. Please choose valid positions.\n";
                        }
                    }
                } else {
                    cout << "Your board is not ready for an attack. Make sure you have cards on the board.\n";
                }

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