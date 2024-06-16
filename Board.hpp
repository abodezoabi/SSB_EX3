// abodezoabi2000@gmail.com

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <map>
#include "Vertex.hpp"
#include "Edge.hpp"
#include "card.hpp"
#include "Player.hpp"
#include <memory>


class Board {
public:
    std::vector<Vertex*> vertices;
    std::vector<Edge*> edges;

    Board();
    ~Board();

    bool canPlaceSettlement(int vertexId) const;
    bool placeSettlement(int vertexId, const std::string& player);
    bool canPlaceRoad(int edgeId) const;
    bool placeRoad(int edgeId, const std::string& player);
    Vertex* findVertexById(int id) const;
    Edge* findEdgeById(int id) const;
    std::unique_ptr<Card> drawDevelopmentCard();
    std::vector<Vertex*> getVertices() const;
//    void monopoly(Player& player, const std::string& resource);
//    Player& getPlayerByName(const std::string& name);


private:
    void initializeVertices();
    void initializeEdges();
    std::vector<Player*> players;
    //Edge* findEdgeById(int id) const;
};

#endif // BOARD_HPP
