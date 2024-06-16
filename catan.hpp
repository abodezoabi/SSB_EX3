// abodezoabi2000@gmail.com

#ifndef CATAN_HPP
#define CATAN_HPP

#include "Player.hpp"
#include "Board.hpp"

class Catan {
private:
    Player* currentPlayer;
    Board board;
  //  Player* players[3];

public:

    Catan(){};
    void initializePlayers(Player& p1, Player& p2, Player& p3) ;
    Player* players[3];
   // Catan(Player& p1, Player& p2, Player& p3);
    void ChooseStartingPlayer();
    Board& getBoard();
    void printWinner(Player& p);
};

#endif // CATAN_HPP
