// abodezoabi2000@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "Player.hpp"
#include "Board.hpp"
#include "card.hpp"
#include "catan.hpp"
using namespace std;
TEST_CASE("Test Player and Board interactions") {
Catan catan;
Player p1("Amit", catan);
Player p2("Yossi", catan);
Player p3("Dana", catan);

catan.initializePlayers(p1, p2, p3);
catan.ChooseStartingPlayer();

Board& board = catan.getBoard();

SUBCASE("Test player initialization") {
CHECK(p1.getName() == "Amit");
CHECK(p2.getName() == "Yossi");
CHECK(p3.getName() == "Dana");
CHECK(p1.getTotalPoints() == 0);
CHECK(p2.getTotalPoints() == 0);
CHECK(p3.getTotalPoints() == 0);
}

SUBCASE("Test resource management") {
p1.addResource("ore", 5);
p1.addResource("wood", 3);
p1.addResource("wheat", 2);

CHECK(p1.getResourceAmount("ore") == 5);
CHECK(p1.getResourceAmount("wood") == 6);
CHECK(p1.getResourceAmount("wheat") == 4);

p1.removeResource("ore", 3);
p1.removeResource("wood", 1);

CHECK(p1.getResourceAmount("ore") == 2);
CHECK(p1.getResourceAmount("wood") == 5);
}

SUBCASE("Test building structures on board") {
// Assuming board and players are set up
// Test placing settlements and roads
p1.placeSettlement(1, board); // Assuming void function

// Check if settlement was placed correctly
Vertex* settlementVertex = board.findVertexById(1);
CHECK(settlementVertex->owner == "Amit");

p1.placeRoad(3, board); // Assuming void function

// Check if road was placed correctly
Edge* roadEdge = board.findEdgeById(3);
CHECK(roadEdge->owner == "Amit");


}

// Add more test cases as needed
}
TEST_CASE("Test buying and using development cards") {
    Catan game;
    Player p1("Alice", game);
    Player p2("Bob", game);
    Player p3("Charlie", game);

    game.initializePlayers(p1, p2, p3);
    game.ChooseStartingPlayer();
    Board& board = game.getBoard();

    SUBCASE("Test buying development card with enough resources") {
        p1.resources["ore"] = 1;
        p1.resources["sheep"] = 1;
        p1.resources["wheat"] = 1;
        p1.buyDevelopmentCard(board);
        CHECK(p1.developmentCards.size() == 1);
    }

    SUBCASE("Test buying development card without enough resources") {
        p1.resources["ore"] = 0;
        p1.resources["sheep"] = 0;
        p1.resources["wheat"] = 0;
        p1.buyDevelopmentCard(board);
        CHECK(p1.developmentCards.size() == 0);
    }

    SUBCASE("Test using development card") {
        p1.resources["ore"] = 1;
        p1.resources["sheep"] = 1;
        p1.resources["wheat"] = 1;
        p1.buyDevelopmentCard(board);
        bool used = p1.useDevelopmentCard(0, board);
        CHECK(used == true);
        CHECK(p1.developmentCards.size() == 0);
    }
}

TEST_CASE("Test trading resources between players") {
    Catan game;
    Player p1("Alice", game);
    Player p2("Bob", game);
    Player p3("Charlie", game);

    game.initializePlayers(p1, p2, p3);
    game.ChooseStartingPlayer();

    p1.resources["ore"] = 3;
    p1.resources["wheat"]=0;
    p2.resources["ore"]=0;
    p2.resources["wheat"] = 2;

    SUBCASE("Test valid trade") {
        p1.trade(p2, "ore", "wheat", 2, 1);
        CHECK(p1.resources["ore"] == 1);
        CHECK(p1.resources["wheat"] == 1);
        CHECK(p2.resources["ore"] == 2);
        CHECK(p2.resources["wheat"] == 1);
    }

    SUBCASE("Test invalid trade - not enough resources") {
        p1.trade(p2, "ore", "wheat", 4, 1);
        CHECK(p1.resources["ore"] == 3);
        CHECK(p2.resources["wheat"] == 2);
    }
}

TEST_CASE("Test winning conditions") {
    Catan game;
    Player p1("Alice", game);
    Player p2("Bob", game);
    Player p3("Charlie", game);

    game.initializePlayers(p1, p2, p3);
    game.ChooseStartingPlayer();

    SUBCASE("Test winning by victory points") {
        p1.addVictoryPoint();
        p1.addVictoryPoint();
        p1.addVictoryPoint();
        p1.addVictoryPoint();
        p1.addVictoryPoint();
        p1.addVictoryPoint();
        p1.addVictoryPoint();
        p1.addVictoryPoint();
        p1.addVictoryPoint();
        CHECK(p1.getTotalPoints() == 9);
    }

    SUBCASE("Test winning by building settlements and cities") {
        p1.addSettlementPoint();// +1
        p1.addSettlementPoint();// +1
        p1.addCityPoint();// +2-1
        p1.addCityPoint();// +2-1
        CHECK(p1.getTotalPoints() == 4);
    }
}

TEST_CASE("Test resource management") {
    Catan game;
    Player p1("Alice", game);
    Player p2("Bob", game);
    Player p3("Charlie", game);

    game.initializePlayers(p1, p2, p3);
    game.ChooseStartingPlayer();

    SUBCASE("Test adding resources") {
        p1.addResource("ore", 3);
        CHECK(p1.getResourceAmount("ore") == 3);
    }

    SUBCASE("Test removing resources") {
        p1.addResource("ore", 3);
        p1.removeResource("ore", 2);
        CHECK(p1.getResourceAmount("ore") == 1);
    }

    SUBCASE("Test not enough resources") {
        p1.addResource("ore", 1);
        CHECK(p1.hasEnoughResources({{"ore", 2}}) == false);
    }

    SUBCASE("Test enough resources") {
        p1.addResource("ore", 3);
        CHECK(p1.hasEnoughResources({{"ore", 2}}) == true);
    }
}
//
//int main(int argc, char** argv) {
//    doctest::Context context(argc, argv);
//    int res = context.run();
//    return res;
//}