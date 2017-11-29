//
// Created by diguie_t on 11/28/2017.
//

#include "EventObserver.hh"

void EventObserver::disconnect(ListenerConnection id) {
    Observator::unregisterObserver(id);
}

void EventObserver::notifyAll() {
    Observator::notifyAllObserver();
}

void EventObserver::notify(const std::string &event) {
    Observator::notifyObserver(event);
}

void EventObserver::notify() {
    Observator::notifyObserver("");
}