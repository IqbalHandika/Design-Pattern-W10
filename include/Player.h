#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <functional>

class Player {
public:
    void subscribe(const std::function<void()>& observer) {
        observers.push_back(observer);
    }

    void attack() {
        // Notify all observers
        for (auto& observer : observers) {
            observer();
        }
    }

private:
    std::vector<std::function<void()>> observers;
};

#endif