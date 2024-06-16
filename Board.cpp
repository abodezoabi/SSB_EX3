// abodezoabi2000@gmail.com

#include "Board.hpp"
#include "Edge.hpp"
#include "card.hpp"
#include "Vertex.hpp"

#include <iostream>

Board::Board() {
    initializeVertices();
    initializeEdges();
}

Board::~Board() {
    for (Vertex* vertex : vertices) {
        delete vertex;
    }
    for (Edge* edge : edges) {
        delete edge;
    }
}
std::vector<Vertex*> Board::getVertices() const {
    return vertices;
}
void Board::initializeVertices() {
    // Initialize vertices based on the Catan map layout.
    // Initialize vertices based on the Catan map layout.
    vertices.push_back(new Vertex(1, {2,2,4}, {"FOREST", "HILLS", "PASTURE"}));
    vertices.push_back(new Vertex(2, {2,2,4}, {"FOREST", "PASTURE", "FIELD"}));
    vertices.push_back(new Vertex(3, {2,2,4}, {"FIELD", "MOUNTAINS", "DESERT"}));
    vertices.push_back(new Vertex(4, {3,2,4}, {"FOREST", "PASTURE", "HILLS"}));
    vertices.push_back(new Vertex(5, {3,2,4}, {"PASTURE", "FIELD", "HILLS"}));
    vertices.push_back(new Vertex(6, {3,2,4}, {"FIELD", "MOUNTAINS", "FOREST"}));
    vertices.push_back(new Vertex(7, {3,2,4}, {"HILLS", "MOUNTAINS", "PASTURE"}));
    vertices.push_back(new Vertex(8, {4,2,4}, {"FOREST", "PASTURE", "DESERT"}));
    vertices.push_back(new Vertex(9, {4,2,4}, {"PASTURE", "FIELD", "HILLS"}));
    vertices.push_back(new Vertex(10, {4,2,4}, {"HILLS", "MOUNTAINS", "FIELD"}));
    vertices.push_back(new Vertex(11, {4,2,4}, {"FIELD", "MOUNTAINS", "FOREST"}));
    vertices.push_back(new Vertex(12, {4,2,4}, {"PASTURE", "MOUNTAINS", "DESERT"}));
    vertices.push_back(new Vertex(13, {5,2,4}, {"FOREST", "HILLS", "PASTURE"}));
    vertices.push_back(new Vertex(14, {5,2,4}, {"FOREST", "PASTURE", "FIELD"}));
    vertices.push_back(new Vertex(15, {5,2,4}, {"FIELD", "MOUNTAINS", "DESERT"}));
    vertices.push_back(new Vertex(16, {5,2,4}, {"HILLS", "MOUNTAINS", "PASTURE"}));
    vertices.push_back(new Vertex(17, {5,2,4}, {"FOREST", "HILLS", "FIELD"}));
    vertices.push_back(new Vertex(18, {5,2,4}, {"PASTURE", "FIELD", "HILLS"}));
    vertices.push_back(new Vertex(19, {5,2,4}, {"HILLS", "MOUNTAINS", "FIELD"}));
    vertices.push_back(new Vertex(20, {5,2,4}, {"FIELD", "MOUNTAINS", "FOREST"}));
    vertices.push_back(new Vertex(21, {6,2,4}, {"PASTURE", "MOUNTAINS", "DESERT"}));
    vertices.push_back(new Vertex(22, {6,2,4}, {"FOREST", "HILLS", "PASTURE"}));
    vertices.push_back(new Vertex(23, {6,2,4}, {"FOREST", "PASTURE", "FIELD"}));
    vertices.push_back(new Vertex(24, {6,2,4}, {"FIELD", "MOUNTAINS", "DESERT"}));
    vertices.push_back(new Vertex(25, {6,2,4}, {"HILLS", "MOUNTAINS", "PASTURE"}));
    vertices.push_back(new Vertex(26, {6,2,4}, {"FOREST", "HILLS", "FIELD"}));
    vertices.push_back(new Vertex(27, {6,2,4}, {"PASTURE", "FIELD", "HILLS"}));
    vertices.push_back(new Vertex(28, {6,2,4}, {"HILLS", "MOUNTAINS", "FIELD"}));
    vertices.push_back(new Vertex(29, {6,2,4}, {"FIELD", "MOUNTAINS", "FOREST"}));
    vertices.push_back(new Vertex(30, {7,2,4}, {"PASTURE", "MOUNTAINS", "DESERT"}));
    vertices.push_back(new Vertex(31, {7,2,4}, {"FOREST", "HILLS", "PASTURE"}));
    vertices.push_back(new Vertex(32, {7,2,4}, {"FOREST", "PASTURE", "FIELD"}));
    vertices.push_back(new Vertex(33, {7,2,4}, {"FIELD", "MOUNTAINS", "DESERT"}));
    vertices.push_back(new Vertex(34, {7,2,4}, {"HILLS", "MOUNTAINS", "PASTURE"}));
    vertices.push_back(new Vertex(35, {7,2,4}, {"FOREST", "HILLS", "FIELD"}));
    vertices.push_back(new Vertex(36, {7,2,4}, {"PASTURE", "FIELD", "HILLS"}));
    vertices.push_back(new Vertex(37, {7,2,4}, {"HILLS", "MOUNTAINS", "FIELD"}));
    vertices.push_back(new Vertex(38, {7,2,4}, {"FIELD", "MOUNTAINS", "FOREST"}));
    vertices.push_back(new Vertex(39, {8,2,4}, {"PASTURE", "MOUNTAINS", "DESERT"}));
    vertices.push_back(new Vertex(40, {8,2,4}, {"FOREST", "HILLS", "PASTURE"}));
    vertices.push_back(new Vertex(41, {8,2,4}, {"FOREST", "PASTURE", "FIELD"}));
    vertices.push_back(new Vertex(42, {8,2,4}, {"FIELD", "MOUNTAINS", "DESERT"}));
    vertices.push_back(new Vertex(43, {8,2,4}, {"HILLS", "MOUNTAINS", "PASTURE"}));
    vertices.push_back(new Vertex(44, {8,2,4}, {"FOREST", "HILLS", "FIELD"}));
    vertices.push_back(new Vertex(45, {8,2,4}, {"PASTURE", "FIELD", "HILLS"}));
    vertices.push_back(new Vertex(46, {8,2,4}, {"HILLS", "MOUNTAINS", "FIELD"}));
    vertices.push_back(new Vertex(47, {8,2,4}, {"FIELD", "MOUNTAINS", "FOREST"}));
    vertices.push_back(new Vertex(48, {8,2,4}, {"PASTURE", "MOUNTAINS", "DESERT"}));
    vertices.push_back(new Vertex(49, {8,2,4}, {"FOREST", "HILLS", "PASTURE"}));
    vertices.push_back(new Vertex(50, {8,2,4}, {"FOREST", "PASTURE", "FIELD"}));
    vertices.push_back(new Vertex(51, {8,2,4}, {"FIELD", "MOUNTAINS", "DESERT"}));
    vertices.push_back(new Vertex(52, {8,2,4}, {"HILLS", "MOUNTAINS", "PASTURE"}));
    vertices.push_back(new Vertex(53, {8,2,4}, {"FOREST", "HILLS", "FIELD"}));
    // Add other vertices...
}

void Board::initializeEdges() {
    // Initialize edges based on the Catan map layout.
    edges.push_back(new Edge(1, vertices[0], vertices[1]));
    edges.push_back(new Edge(2, vertices[0], vertices[4]));
    edges.push_back(new Edge(3, vertices[1], vertices[2]));
    edges.push_back(new Edge(4, vertices[1], vertices[5]));
    edges.push_back(new Edge(5, vertices[2], vertices[3]));
    edges.push_back(new Edge(6, vertices[3], vertices[6]));
    edges.push_back(new Edge(7, vertices[4], vertices[7]));
    edges.push_back(new Edge(8, vertices[4], vertices[8]));
    edges.push_back(new Edge(9, vertices[5], vertices[9]));
    edges.push_back(new Edge(10, vertices[5], vertices[10]));
    edges.push_back(new Edge(11, vertices[6], vertices[11]));
    edges.push_back(new Edge(12, vertices[7], vertices[12]));
    edges.push_back(new Edge(13, vertices[7], vertices[13]));
    edges.push_back(new Edge(14, vertices[8], vertices[14]));
    edges.push_back(new Edge(15, vertices[8], vertices[15]));
    edges.push_back(new Edge(16, vertices[9], vertices[16]));
    edges.push_back(new Edge(17, vertices[9], vertices[17]));
    edges.push_back(new Edge(18, vertices[10], vertices[18]));
    edges.push_back(new Edge(19, vertices[10], vertices[19]));
    edges.push_back(new Edge(20, vertices[11], vertices[20]));
    edges.push_back(new Edge(21, vertices[12], vertices[21]));
    edges.push_back(new Edge(22, vertices[13], vertices[22]));
    edges.push_back(new Edge(23, vertices[14], vertices[23]));
    edges.push_back(new Edge(24, vertices[15], vertices[24]));
    edges.push_back(new Edge(25, vertices[16], vertices[25]));
    edges.push_back(new Edge(26, vertices[17], vertices[26]));
    edges.push_back(new Edge(27, vertices[18], vertices[27]));
    edges.push_back(new Edge(28, vertices[19], vertices[28]));
    edges.push_back(new Edge(29, vertices[20], vertices[29]));
    edges.push_back(new Edge(30, vertices[21], vertices[30]));
    edges.push_back(new Edge(31, vertices[22], vertices[31]));
    edges.push_back(new Edge(32, vertices[23], vertices[32]));
    edges.push_back(new Edge(33, vertices[24], vertices[33]));
    edges.push_back(new Edge(34, vertices[25], vertices[34]));
    edges.push_back(new Edge(35, vertices[26], vertices[35]));
    edges.push_back(new Edge(36, vertices[27], vertices[36]));
    edges.push_back(new Edge(37, vertices[28], vertices[37]));
    edges.push_back(new Edge(38, vertices[29], vertices[38]));
    edges.push_back(new Edge(39, vertices[30], vertices[39]));
    edges.push_back(new Edge(40, vertices[31], vertices[40]));
    edges.push_back(new Edge(41, vertices[32], vertices[41]));
    edges.push_back(new Edge(42, vertices[33], vertices[42]));
    edges.push_back(new Edge(43, vertices[34], vertices[43]));
    edges.push_back(new Edge(44, vertices[35], vertices[44]));
    edges.push_back(new Edge(45, vertices[36], vertices[45]));
    edges.push_back(new Edge(46, vertices[37], vertices[46]));
    edges.push_back(new Edge(47, vertices[38], vertices[47]));
    edges.push_back(new Edge(48, vertices[39], vertices[48]));
    edges.push_back(new Edge(49, vertices[40], vertices[49]));
    edges.push_back(new Edge(50, vertices[41], vertices[50]));
    edges.push_back(new Edge(51, vertices[42], vertices[51]));
    edges.push_back(new Edge(52, vertices[43], vertices[52]));
    edges.push_back(new Edge(53, vertices[44], vertices[53]));
    edges.push_back(new Edge(54, vertices[1], vertices[2]));
    edges.push_back(new Edge(55, vertices[4], vertices[5]));
    edges.push_back(new Edge(56, vertices[7], vertices[8]));
    edges.push_back(new Edge(57, vertices[10], vertices[11]));
    edges.push_back(new Edge(58, vertices[13], vertices[14]));
    edges.push_back(new Edge(59, vertices[16], vertices[17]));
    edges.push_back(new Edge(60, vertices[19], vertices[20]));
    edges.push_back(new Edge(61, vertices[22], vertices[23]));
    edges.push_back(new Edge(62, vertices[25], vertices[26]));
    edges.push_back(new Edge(63, vertices[28], vertices[29]));
    edges.push_back(new Edge(64, vertices[31], vertices[32]));
    edges.push_back(new Edge(65, vertices[34], vertices[35]));
    edges.push_back(new Edge(66, vertices[37], vertices[38]));
    edges.push_back(new Edge(67, vertices[40], vertices[41]));
    edges.push_back(new Edge(68, vertices[43], vertices[44]));
    edges.push_back(new Edge(69, vertices[46], vertices[47]));
    edges.push_back(new Edge(70, vertices[49], vertices[50]));
    edges.push_back(new Edge(71, vertices[52], vertices[53]));
}

Vertex* Board::findVertexById(int id) const {
    for (Vertex* vertex : vertices) {
        if (vertex->id == id) {
            return vertex;
        }
    }
    return nullptr;
}

Edge* Board::findEdgeById(int id) const {
    for (Edge* edge : edges) {
        if (edge->id == id) {
            return edge;
        }
    }
    return nullptr;
}

bool Board::canPlaceSettlement(int vertexId) const {
    Vertex* vertex = findVertexById(vertexId);
    return vertex && !vertex->hasSettlement;
}

bool Board::placeSettlement(int vertexId, const std::string& player) {
    if (canPlaceSettlement(vertexId)) {
        Vertex* vertex = findVertexById(vertexId);
        if (vertex) {
            vertex->hasSettlement = true;
            vertex->owner = player;
            std::cout << player << " placed a settlement at intersection: " << vertexId << " with land types: "<< std::endl;
            for (size_t i = 0; i < vertex->landTypes.size(); ++i) {
                std::cout << vertex->landTypes[i] << " no: " << vertex->landNumbers[i] << std::endl;
            }
            std::cout << std::endl;
            return true;
        }
    }
    return false;
}

bool Board::canPlaceRoad(int edgeId) const {
    Edge* edge = findEdgeById(edgeId);
    return edge && !edge->isOccupied();
}

bool Board::placeRoad(int edgeId, const std::string& player) {
    if (canPlaceRoad(edgeId)) {
        Edge* edge = findEdgeById(edgeId);
        edge->owner = player;
        return true;
    }
    return false;

}

