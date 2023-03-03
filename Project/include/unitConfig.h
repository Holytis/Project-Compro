#include "libary.h"

class Unit
{
    public:
        std::string unitType;
        int moveType;
        int position;
        bool kill = false;
        bool isMove = false;
        bool firstMove = false;
        bool canAttack = false;
        bool isDead = false;
        std::vector<int> target;
        sf::Sprite entity;
        sf::Texture texture;
        void loadTextures(const std::string);
        void entityConfig(const std::string, sf::Vector2f, sf::RectangleShape);
};

void Unit::loadTextures(const std::string pE)
{
    if (!texture.loadFromFile(pE))
    {
        std::cout << "Cannot load texture " << pE << std::endl;
    }
    texture.setSmooth(true);
};

void Unit::entityConfig(const std::string pE, sf::Vector2f bP, sf::RectangleShape Status)
{
    sf::Vector2f leftBottom = Status.getPosition();
    leftBottom.y += Status.getSize().y / 1.70f; // 1.50f
    if (unitType == "Enemy")
    {
        // std::cout << unitType << std::endl;
        loadTextures(pE);
        entity.setTexture(texture);
        entity.setScale(sf::Vector2f(0.45f, 0.45f)); // 0.45 || 0.65
        entity.setPosition(bP);
    }
    else if (unitType == "Player")
    {
        loadTextures(pE);
        entity.setTexture(texture);
        entity.setScale(sf::Vector2f(0.25f, 0.25f)); // 0.25 || 0.3
        entity.setPosition(leftBottom);
    }
}