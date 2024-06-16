// abodezoabi2000@gmail.com
#include "card.hpp"
#include "Player.hpp"

void KnightCard::useEffect(Player& player) const {
    player.addKnight();
}

std::string KnightCard::getType() const {
    return "Knight";
}

void VictoryPointCard::useEffect(Player& player) const {
    player.addVictoryPoint();
}

std::string VictoryPointCard::getType() const {
    return "VictoryPoint";
}

MonopolyCard::MonopolyCard(const std::string& resource) : resource(resource) {}

void MonopolyCard::useEffect(Player& player) const {

    int totalAmount = 0;
    for (Player* otherPlayer : player.getAllPlayersExceptSelf()) {
        int amount = otherPlayer->getResourceAmount(resource);
        totalAmount += amount;
        otherPlayer->removeResource(resource, amount);
    }
    player.addResource(resource, totalAmount);
}

std::string MonopolyCard::getType() const {
    return "Monopoly";
}

void RoadBuildingCard::useEffect(Player& player) const {
    player.buildRoadForFree(2);
}

std::string RoadBuildingCard::getType() const {
    return "RoadBuilding";
}

YearOfPlentyCard::YearOfPlentyCard(const std::string& resource1, const std::string& resource2)
        : resource1(resource1), resource2(resource2) {}

void YearOfPlentyCard::useEffect(Player& player) const {

    player.addResource(resource1, 1);
    player.addResource(resource2, 1);
}

std::string YearOfPlentyCard::getType() const {
    return "YearOfPlenty";
}
