#include <iostream>
#include <string>
#include <vector>


class Entity {
protected:
    std::string name;
    int health;

public:
    Entity(const std::string& n, int h) : name(n), health(h) {}

    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health << std::endl;
    }

    virtual ~Entity() {}
};


class Player : public Entity {
private:
    int experience;

public:
    Player(const std::string& n, int h, int exp)
        : Entity(n, h), experience(exp) {
    }

    void displayInfo() const override {
        Entity::displayInfo();
        std::cout << "Experience: " << experience << std::endl;
    }
};


class Enemy : public Entity {
private:
    std::string type;

public:
    Enemy(const std::string& n, int h, const std::string& t)
        : Entity(n, h), type(t) {
    }

    void displayInfo() const override {
        Entity::displayInfo();
        std::cout << "Type: " << type << std::endl;
    }
};

template <typename T>
class GameManager {
private:
    std::vector<T> entities;

public:
    void addEntity(const T& entity) {
        entities.push_back(entity);
    }

    void displayAll() const {
        for (const auto& entity : entities) {
            entity->displayInfo();
        }
    }
};


template <typename T>
class Queue {
private:
    std::vector<T> items;

public:
    void push(const T& item) {
        items.push_back(item);
    }


    void pop() {
        if (!items.empty()) {
            items.erase(items.begin());
        }
        else {
            std::cout << "Queue is empty. Nothing to pop.\n";
        }
    }

    void display() const {
        std::cout << "Queue contents:\n";
        for (const auto& item : items) {
            std::cout << item << std::endl;
        }
    }
};


int main() {

    GameManager<Entity*> manager;
    manager.addEntity(new Player("Hero", 100, 0));
    manager.addEntity(new Enemy("Goblin", 50, "Goblin"));

    std::cout << "GameManager Entities:\n";
    manager.displayAll();

    Queue<std::string> stringQueue;
    stringQueue.push("Sword");
    stringQueue.push("Bow");
    stringQueue.push("Shield");
    stringQueue.display();

    stringQueue.pop();
    stringQueue.display();

    
    return 0;
}