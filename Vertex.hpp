// abodezoabi2000@gmail.com
#ifndef VERTEX_HPP
#define VERTEX_HPP
#include <vector>
#include <string>

class Vertex {
public:
    int id;
    std::vector<int> landNumbers;
    std::vector <std::string> landTypes;
    bool hasSettlement;
    bool hasCity;
    std::string owner;

    Vertex(int id, const std::vector<int> &landNumbers, const std::vector <std::string> &landTypes);
};

#endif // VERTEX_HPP
