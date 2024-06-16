// abodezoabi2000@gmail.com

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Board.hpp"
#include "card.hpp"


class Catan;
class Board;
//class Card;
class Player {
public:
    std::string name;
    std::map<std::string, int> resources;
   // std::vector<Card> developmentCards;
    int knights;
    int victoryPoints;
    int settlementPoints;
    int cityPoints;
    bool isTurn;// Flag for turns
    Catan& catan; // Reference to the Catan game
    std::vector<Card*> developmentCards; // Vector of pointers to Card objects

    Player(const std::string& name,Catan& catan);
    void placeSettlement(int vertexId, Board& board);
    void placeRoad(int edgeId, Board& board);
    void rollDice(Board& board);
    void startTurn();
    void endTurn();
    void printPoints();
//    void addCard(Card* card);
//    void useCard(int index); // Use card at index
    void trade(Player& other, const std::string& give, const std::string& receive, int giveAmount, int receiveAmount);
    void buyDevelopmentCard(Board& board);
    void printResources() const;
    bool useDevelopmentCard(int cardIndex, Board& board);
    void addKnight();
    void addSettlementPoint();
    void addCityPoint();
    int getTotalPoints() const;
    std::string getName() const;
    void addVictoryPoint();
    void decreaseResources(const std::map<std::string, int>& cost);
    bool buildCity(int vertexId, Board& board);
    bool hasEnoughResources(const std::map<std::string, int>& cost) const;
    int getResourceAmount(const std::string& resource) const;
    void addResource(const std::string& resource, int amount);
    void removeResource(const std::string& resource, int amount);
    std::vector<Player*> getAllPlayersExceptSelf() const;
    void buildRoadForFree(int roadCount);

};

#endif // PLAYER_HPP
