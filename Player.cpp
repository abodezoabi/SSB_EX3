// abodezoabi2000@gmail.com

#include "Player.hpp"
#include "card.hpp"
#include "catan.hpp"
#include <iostream>
#include <cstdlib> // For rand()
#include <ctime> // For time()
Player::Player(const std::string& name, Catan& catan) : name(name),knights(0), victoryPoints(0), settlementPoints(0),
cityPoints(0), catan(catan), isTurn(false)
{
    // Initialize starting resources to place on lands
    //
    resources["wood"] = 3;
    resources["brick"] = 3;
    resources["wheat"] = 2;
    resources["sheep"] = 2;
    resources["ore"] = 0;
    std::srand(std::time(0));
}

void Player::placeSettlement(int vertexId, Board& board) {
    if (!isTurn) {
        std::cout << "Cannot place settlement - it's not " << name << "'s turn." << std::endl;

    }

    std::map<std::string, int> settlementCost = {{"brick", 1}, {"wood", 1}, {"wheat", 1}, {"sheep", 1}};
    if (!hasEnoughResources(settlementCost)) {
        std::cout << "Not enough resources to place a settlement." << std::endl;

    }

    if (hasEnoughResources(settlementCost) && board.placeSettlement(vertexId, name) && isTurn) {
        decreaseResources(settlementCost);
        this->settlementPoints += 1;
       // std::cout << name << " placed a settlement at vertex " << vertexId << std::endl;
    } else {
        std::cout << name << " cannot place a settlement at vertex " << vertexId << std::endl;
    }
}


void Player::placeRoad(int edgeId, Board& board) {
    if (!isTurn) {
        std::cout << "Cannot place road - it's not " << name << "'s turn." << std::endl;

    }

    std::map<std::string, int> roadCost = {{"brick", 1}, {"wood", 1}};
    if (!hasEnoughResources(roadCost)) {
        std::cout << "Not enough resources to place a road." << std::endl;

    }

    if (hasEnoughResources(roadCost) && board.placeRoad(edgeId, name) && isTurn) {
        decreaseResources(roadCost);
        std::cout << name << " placed a road at edge " << edgeId << std::endl;
    } else {
        std::cout << name << " cannot place a road at edge " << edgeId << std::endl;
    }
}


bool Player::hasEnoughResources(const std::map<std::string, int>& cost) const {
    for (const auto& resource : cost) {
        if (resources.at(resource.first) < resource.second) {
            return false;
        }
    }
    return true;
}
void Player::decreaseResources(const std::map<std::string, int>& cost) {
    for (const auto& resource : cost) {
        resources[resource.first] -= resource.second;
    }
}
bool Player::buildCity(int vertexId, Board& board) {
    if (!isTurn) {
        std::cout << "Cannot place road - it's not " << name << "'s turn." << std::endl;
    }

    std::map<std::string, int> cityCost = {{"ore", 3}, {"wheat", 2}};
    if (!hasEnoughResources(cityCost)) {
        std::cout << "Not enough resources to build a city." << std::endl;
        return false;
    }

    Vertex* vertex = board.findVertexById(vertexId);
    if (vertex == nullptr || vertex->owner != name || !vertex->hasSettlement || vertex->hasCity) {
        std::cout << "Cannot build a city at this location." << std::endl;
        return false;
    }

    decreaseResources(cityCost);
    vertex->hasCity = true; // add a city
    vertex->hasSettlement = false; // Remove settlement
    settlementPoints -= 1; // Cities give 2 points in total, but since the player already has 1 point from the settlement, we add 2 minus 1
    cityPoints +=2;
    std::cout <<name <<"'s Settlement removed and Built a city at vertex " << vertexId << "." << std::endl;
    return true;
}


void Player::buyDevelopmentCard(Board& board) {
    if (resources["ore"] >= 1 && resources["sheep"] >= 1 && resources["wheat"] >= 1) {
        resources["ore"]--;
        resources["sheep"]--;
        resources["wheat"]--;

        int cardType = std::rand() % 5;
        Card* newCard;

        switch (cardType) {
            case 0:
                newCard = new KnightCard();
                break;
            case 1:
                newCard = new VictoryPointCard();
                break;
            case 2:
                newCard = new MonopolyCard("wood"); // For simplicity, choose a resource
                break;
            case 3:
                newCard = new RoadBuildingCard();
                break;
            case 4:
                newCard = new YearOfPlentyCard("wheat", "ore"); // For simplicity, choose resources
                break;
            default:
                throw std::runtime_error("Invalid card type.");
        }
        std::cout<< name << " received: " << newCard->getType() <<std::endl;
        developmentCards.push_back(newCard);
    } else {
        std::cout << name << " does not have enough resources to buy a development card." << std::endl;
    }
}

bool Player::useDevelopmentCard(int index, Board& board) {
    if (index < 0 || index >= developmentCards.size()) {
        std::cout << "Invalid card index." << std::endl;
        return false;
    }

    developmentCards[index]->useEffect(*this); // Call useEffect through pointer
    delete developmentCards[index];
    developmentCards.erase(developmentCards.begin() + index); // Remove the card from the vector
    return true;
}

void Player::addKnight() {
    knights++;
    if (knights >= 3) {
       std::cout<<this->getName()<<"Has unlocked greatest army of 3 knights"<<std::endl;
      this->victoryPoints+=2;
    }
}

void Player::rollDice(Board& board) {
    if (!isTurn) {
        std::cout << "Cannot roll dice - it's not " << name << "'s turn." << std::endl;
        return;
    }

    // Roll the dice
    int diceRoll = (rand() % 6 + 1) + (rand() % 6 + 1);
    std::cout << name << " rolled the dice and got: " << diceRoll << std::endl;

    // Check each vertex and assign resources based on the dice roll
    for (const auto& vertex : board.getVertices()) {
        if (vertex->owner == name) {
            for (size_t i = 0; i < vertex->landNumbers.size(); ++i) {
                if (vertex->landNumbers[i] == diceRoll) {
                    std::string resource = vertex->landTypes[i];
                    resources[resource]++;
                    std::cout << name << " received 1 " << resource << " from tile number " << vertex->landNumbers[i] << std::endl;
                }
            }
        }
    }
}

void Player::startTurn() {
    isTurn = true;
    std::cout << name << "'s turn started." << std::endl;
}

void Player::endTurn() {
    std::cout << name << " ended their turn." << std::endl;
    if (getTotalPoints() >= 10) {
        catan.printWinner(*this);

    }
}

void Player::printPoints() {
    std::cout << name << " has "<<this->getTotalPoints()<<" points"<< std::endl;
}

void Player::trade(Player& other, const std::string& give, const std::string& receive, int giveAmount, int receiveAmount) {
    // Check if both players have enough resources
    if (resources[give] < giveAmount) {
        std::cout << name << " does not have enough " << give << " to trade." << std::endl;
        return;
    }

    if (other.resources[receive] < receiveAmount) {
        std::cout << other.name << " does not have enough " << receive << " to trade." << std::endl;
        return;
    }

    // Perform the trade
    resources[give] -= giveAmount;
    resources[receive] += receiveAmount;
    other.resources[receive] -= receiveAmount;
    other.resources[give] += giveAmount;

    std::cout << name << " traded " << giveAmount << " " << give << " with " << other.name << " for " << receiveAmount << " " << receive << "." << std::endl;
}


void Player::addVictoryPoint() {
    victoryPoints++;
}

void Player::addSettlementPoint() {
    settlementPoints++;
}

void Player::addCityPoint() {
    //cityPoints += 2;
    cityPoints++;
}

int Player::getTotalPoints() const {
    return victoryPoints + settlementPoints + cityPoints;
}
int Player::getResourceAmount(const std::string& resource) const {
    auto it = resources.find(resource);
    return it != resources.end() ? it->second : 0;
}

void Player::addResource(const std::string& resource, int amount) {
    resources[resource] += amount;
}

void Player::removeResource(const std::string& resource, int amount) {
    resources[resource] -= amount;
    if (resources[resource] < 0) {
        resources[resource] = 0;
    }
}

std::string Player::getName() const {
    return name;
}

void Player::printResources() const {
    std::cout << "Resources of player " << name << ":" << std::endl;
    for (const auto& resource : resources) {
        std::cout << resource.first << ": " << resource.second << std::endl;
    }
    std::cout << std::endl;
}

std::vector<Player*> Player::getAllPlayersExceptSelf() const {
    std::vector<Player*> otherPlayers;


    for (Player* player : catan.players) {
        if (player != this) {
            otherPlayers.push_back(player);
        }
    }

    return otherPlayers;
}

void Player::buildRoadForFree(int roadCount) {

    if (isTurn) {

        Board& board = catan.getBoard();

        int currentEdgeIndex =10;

        for (int i = 0; i < roadCount; ++i) {
            placeRoad(currentEdgeIndex, board);
            currentEdgeIndex++;
        }

        std::cout << name << " is building " << roadCount << " roads for free." << std::endl;
    } else {
        std::cout << "It's not " << name << "'s turn to build roads for free." << std::endl;
    }
}