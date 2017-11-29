//
// Created by diguie_t on 11/25/2017.
//

#ifndef MVC_TEST_OBSERVER_HPP
#define MVC_TEST_OBSERVER_HPP

#include <functional>  // for std::function
#include <utility>     // for std::forward and std::move
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

using ListenerConnection = unsigned long int;

template<typename EventType>
class Observator {
public:
    using Listener = std::function<bool()>;

private:
    std::unordered_map<EventType, std::unordered_map<ListenerConnection, Listener>> _observers;
    ListenerConnection _curId;

private:
    ListenerConnection getNewId() {
        return (++this->_curId);
    }

    void unregisterIds(const std::vector<ListenerConnection> &ids) {
        if (ids.empty())
            return;

        for (const ListenerConnection &id : ids) {
            for (auto &listeners : this->_observers) {
                std::unordered_map<ListenerConnection, Listener> &eventListeners = listeners.second;
                for(auto it = eventListeners.begin(); it != eventListeners.end(); ) {
                    if(it->first == id)
                        it = eventListeners.erase(it);
                    else
                        ++it;
                }
            }
        }
    }

public:
    Observator() : _curId(0) {

    }

    virtual ~Observator() {

    }

    template<typename Observer>
    ListenerConnection registerObserver(const EventType &event, Observer &&observer) {
        ListenerConnection id = this->getNewId();

        _observers[event].insert(std::pair<ListenerConnection, Listener>(id, std::forward<Observer>(observer)));
        return (id);
    }

    template<typename Observer>
    ListenerConnection registerObserver(EventType &&event, Observer &&observer) {
        ListenerConnection id = this->getNewId();

        _observers[std::move(event)].insert(
                std::pair<ListenerConnection, Listener>(id, std::forward<Observer>(observer)));
        return (id);
    }

    void unregisterObserver(const EventType &event, ListenerConnection id) {
        auto result = this->_observers.find(event);
        if (result != this->_observers.end()) {
            result->second.erase(id);
        }
    }

    void unregisterObserver(ListenerConnection id) {
        for (auto const &eventsObservers : this->_observers) {
            ListenerConnection prevSize = eventsObservers.second.size();
            this->unregisterObserver(eventsObservers.first, id);
            if (prevSize != eventsObservers.second.size()) {
                return;
            }
        }
    }

    void notifyObserver(const EventType &event) {
        std::vector<ListenerConnection> toRemove;

        auto result = this->_observers.find(event);
        if (result != this->_observers.end()) {
            for (const auto &obs : result->second) {
                if (obs.second()) {
                    toRemove.emplace_back(obs.first);
                }
            }
        }

        this->unregisterIds(toRemove);
    }

    void notifyAllObserver() {
        std::vector<ListenerConnection> toRemove;

        for (const auto obsEvents : this->_observers) {
            for (const auto &obs : obsEvents.second) {
                if (obs.second()) {
                    toRemove.emplace_back(obs.first);
                }
            }
        }

        this->unregisterIds(toRemove);
    }
};

#endif //MVC_TEST_OBSERVER_HPP
