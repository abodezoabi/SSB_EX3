// abodezoabi2000@gmail.com

#include "Vertex.hpp"

Vertex::Vertex(int id, const std::vector<int>& landNumbers, const std::vector<std::string>& landTypes)
        : id(id),landNumbers(landNumbers), landTypes(landTypes), hasSettlement(false), owner("") {}
