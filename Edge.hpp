// abodezoabi2000@gmail.com

#ifndef EDGE_HPP
#define EDGE_HPP

#include "Vertex.hpp"

class Edge {
public:
    int id;
    Vertex* v1;
    Vertex* v2;
    std::string owner;

    Edge(int id, Vertex* v1, Vertex* v2);
    bool isOccupied() const;
};

#endif // EDGE_HPP
