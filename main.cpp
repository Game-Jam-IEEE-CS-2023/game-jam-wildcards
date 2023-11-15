// Run main
#include "Player.h"
#include <iostream>
#include "helpers.h"
#include <filesystem>
#include "Board.h"
#include <cstdlib> // Include this for rand() function
#include <ctime>   // Include this for seeding rand()

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

    cout << "Hahaha, it seems that you have presented at last to help the poor man that trapped me in here!" << endl;

    cout << "Know that you do not have even the slightest of chances at defeating me!!!" << endl;

    cout << ". . . Oh? You heard of my challenge and came to face me?! Hahah! Fool, I will make of this digital plane...\n Your new grave!!!" << endl;
    system("pause");
    cout << "En garde, man of flesh!!!" << endl;

    // Seed the random number generator
    std::srand(std::time(0));

    // Simulate the game loop
    while (player1.getHealth() > 0 && player2.getHealth() > 0) {
        // Player's turn
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
                        player2.takeDamage(playerCard.getCardAtk());
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

                break;
            case 5:
                // End the player's turn
                player1.replenishEnergy();
                player2.replenishEnergy();
                break;
            default:
                std::cout << "Invalid choice. Please choose a valid option.\n";
                break;
        }

        // Check if the player has won after their turn
        if (player2.getHealth() <= 0) {
            std::cout << "Congratulations! You defeated Vermius!\n";
            break;
        }

        // Vermius's turn
        int vermiusChoice = std::rand() % 2 + 1; // Randomly choose between 1 and 2
        switch (vermiusChoice) {
            case 1:
                // Vermius places a card
                Card vermiusCard = player2.chooseCardFromHand();
                if (!vermiusCard.getCardName().empty()) {
                    enemy_board.addCardToBoard(vermiusCard);
                    std::cout << "Vermius placed a card on the board!\n";
                    enemy_board.displayBoard();
                }
                break;
            case 2:
                // Vermius attacks
                if (!enemy_board.isFull()) {
                    int enemyPosition = std::rand() % 3; // Randomly choose position (0, 1, or 2)
                    if (player_board.isEmpty()) {
                        player1.takeDamage(player2.calculateAttackDamage());
                    } else {
                        int playerPosition = std::rand() % 3; // Randomly choose position (0, 1, or 2)
                        Card& playerCard = player_board.getCardAtPosition(playerPosition);
                        if (enemyPosition >= 0 && enemyPosition < 3) {
                            Card& enemyCard = enemy_board.getCardAtPosition(enemyPosition);
                            if (playerCard.getCardAtk() < enemyCard.getCardDef()) {
                                std::cout << "Your defending card deflects Vermius's attack!\n";
                            } else if (playerCard.getCardDef() < enemyCard.getCardAtk()) {
                                std::cout << "Vermius's attacking card eliminates your defending card!\n";
                                player_board.removeCardAtPosition(playerPosition);
                            } else {
                                std::cout << "Both cards are destroyed in battle!\n";
                                player_board.removeCardAtPosition(playerPosition);
                                enemy_board.removeCardAtPosition(enemyPosition);
                            }
                        }
                    }
                } else {
                    std::cout << "Vermius's board is not ready for an attack. Make sure he has cards on the board.\n";
                }
                break;
        }

        // Check if Vermius has won after his turn
        if (player1.getHealth() <= 0) {
            std::cout << "Game over! Vermius defeated you.\n";
            break;
        }
    }

    return 0;
}