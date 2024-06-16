#ifndef CARD_HPP
#define CARD_HPP

#include <string>

class Player; // Forward declaration

class Card {
public:
    virtual ~Card() = default;
    virtual void useEffect(Player& player) const = 0;
    virtual std::string getType() const = 0;
};

class KnightCard : public Card {
public:
    void useEffect(Player& player) const override;
    std::string getType() const override;
};

class VictoryPointCard : public Card {
public:
    void useEffect(Player& player) const override;
    std::string getType() const override;
};

class MonopolyCard : public Card {
public:
    explicit MonopolyCard(const std::string& resource);
    void useEffect(Player& player) const override;
    std::string getType() const override;

private:
    std::string resource;
};

class RoadBuildingCard : public Card {
public:
    void useEffect(Player& player) const override;
    std::string getType() const override;
};

class YearOfPlentyCard : public Card {
public:
    explicit YearOfPlentyCard(const std::string& resource1, const std::string& resource2);
    void useEffect(Player& player) const override;
    std::string getType() const override;

private:
    std::string resource1;
    std::string resource2;
};

#endif // CARD_HPP
