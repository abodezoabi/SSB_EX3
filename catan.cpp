// abodezoabi2000@gmail.com

#include "catan.hpp"
#include <iostream>

//Catan::Catan(Player& p1, Player& p2, Player& p3) {
//    players[0] = &p1;
//    players[1] = &p2;
//    players[2] = &p3;
//    currentPlayer = &p1; // Default starting player
//}
void Catan::initializePlayers(Player& p1, Player& p2, Player& p3){
    players[0] = &p1;
    players[1] = &p2;
    players[2] = &p3;
}

void Catan::ChooseStartingPlayer() {
    std::cout << "Starting player is " <<players[0]->getName() << "." << std::endl;
}

Board& Catan::getBoard() {
    return board;
}

void Catan::printWinner(Player& p) {

    std::cout <<p.getName() <<" IS THE WINNER with " <<p.getTotalPoints()<<" POINTS"<<std::endl;
}
