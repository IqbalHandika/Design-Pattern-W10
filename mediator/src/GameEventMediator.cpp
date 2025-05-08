#include "GameEventMediator.h"
#include <iostream>

void GameEventMediator::registerListener(const std::string& event, const std::function<void()>& listener) {
    listeners[event].push_back(listener);
}

void GameEventMediator::triggerEvent(const std::string& event) {
    if (listeners.find(event) != listeners.end()) {
        for (const auto& listener : listeners[event]) {
            listener();
        }
    } else {
        std::cout << "No listeners for event: " << event << std::endl;
    }
}