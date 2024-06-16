// abodezoabi2000@gmail.com

#include "Edge.hpp"

Edge::Edge(int id, Vertex* v1, Vertex* v2) : id(id), v1(v1), v2(v2), owner("") {}

bool Edge::isOccupied() const {
    return !owner.empty();
}
