// abodezoabi2000@gmail.com
#include <iostream>
#include <stdexcept>
#include "catan.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "card.hpp"

int main() {
    // Create an instance of the Catan game
    Catan catan;

    // Initialize players with a reference to the Catan game
    Player p1("Amit", catan);
    Player p2("Yossi", catan);
    Player p3("Dana", catan);

    // Add players to the Catan game
    catan.initializePlayers(p1, p2, p3);
    catan.ChooseStartingPlayer(); // Assumes this function sets the starting player

    // Get the reference to the board
    Board& board = catan.getBoard();
    p1.startTurn();
    // Place initial settlements and roads
    p1.placeSettlement(1, board);
    p1.placeRoad(1, board);
    p1.placeSettlement(2, board);
    p1.placeRoad(2, board);
    p1.endTurn();
    p2.startTurn();
    p2.placeSettlement(3, board);
    p2.placeRoad(3, board);
    try {
        p3.placeSettlement(3, board); // p3 tries to place a settlement in the same location as p2.
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    p2.placeSettlement(4, board);
    p2.placeRoad(4, board);
    p2.endTurn();
    p3.startTurn();
    p3.placeSettlement(5, board);
    p3.placeRoad(5, board);
    p3.placeSettlement(6, board);
    p3.placeRoad(6, board);
    p3.endTurn();
    // Example turns
    p1.startTurn(); // Start player 1's turn
    p1.rollDice(board); // Roll the dice
    p1.placeRoad(7, board); // Example of placing a road
    p1.endTurn(); // End player 1's turn

    p2.startTurn(); // Start player 2's turn
    p2.rollDice(board); // Roll the dice
    p2.endTurn(); // End player 2's turn

    p3.startTurn(); // Start player 3's turn
    p3.rollDice(board); // Roll the dice
    p3.endTurn(); // End player 3's turn

    // Example of trying to roll the dice when it's not the player's turn
    try {
        p2.startTurn();
        p2.rollDice(board); // This will throw an exception
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Additional game actions
    p1.startTurn(); // Start player 1's turn again
    p1.rollDice(board); // Roll the dice
    p1.trade(p2, "wood", "brick", 1, 1); // Example trade between players
    p1.endTurn(); // End player 1's turn

    p2.startTurn(); // Start player 2's turn
    p2.buyDevelopmentCard(board); // Example of buying a development card
    p2.endTurn(); // End player 2's turn

   // Print points of all players at the end
    p1.printPoints();
    p2.printPoints();
    p3.printPoints();


     //catan.printWinner();

    return 0;
}
