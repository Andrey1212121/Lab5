#include <iostream>
#include <memory>
#include <vector>


class Entity {
public:
    virtual void displayInfo() const = 0;
    virtual ~Entity() = default;
};


class Player : public Entity {
    std::string name;
    int health;
    int score;
public:
    Player(const std::string& name, int health, int score)
        : name(name), health(health), score(score) {
    }
    void displayInfo() const override {
        std::cout << "Player: " << name << ", Health: " << health << ", Score: " << score << '\n';
    }
};


class Enemy : public Entity {
    std::string name;
    int health;
    std::string type;
public:
    Enemy(const std::string& name, int health, const std::string& type)
        : name(name), health(health), type(type) {
    }
    void displayInfo() const override {
        std::cout << "Enemy: " << name << ", Health: " << health << ", Type: " << type << '\n';
    }
};

// Шаблонный класс очереди
template <typename T>
class Queue {
    std::vector<T> entities;
public:
    void addEntity(const T& entity) {
        entities.push_back(entity);
    }
    void popEntity() {
        if (!entities.empty()) {
            entities.erase(entities.begin());
        }
    }
    void displayAll() const {
        for (const auto& entity : entities) {
            entity->displayInfo();
        }
    }
};

int main() {

    Queue<std::shared_ptr<Entity>> manager;
    manager.addEntity(std::make_shared<Player>("Player", 100, 1));
    manager.addEntity(std::make_shared<Enemy>("Zombie", 70, "Zombie"));
    manager.displayAll();

    return 0;
}