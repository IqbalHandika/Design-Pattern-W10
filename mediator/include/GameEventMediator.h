#ifndef GAME_EVENT_MEDIATOR_H
#define GAME_EVENT_MEDIATOR_H

#include <unordered_map>
#include <vector>
#include <functional>
#include <string>

class GameEventMediator {
public:
    void registerListener(const std::string& event, const std::function<void()>& listener);
    void triggerEvent(const std::string& event);

private:
    std::unordered_map<std::string, std::vector<std::function<void()>>> listeners;
};

#endif