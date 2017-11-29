//
// Created by diguie_t on 11/28/2017.
//

#ifndef MVC_TEST_EVENTOBSERVER_HH
#define MVC_TEST_EVENTOBSERVER_HH

#include <string>
#include "IEventObserver.hh"
#include "../pattern/Observator.hpp"

class EventObserver : public IEventObserver, protected Observator<std::string> {
public:

    template<typename Observer>
    ListenerConnection connect(const std::string &event, Observer &&observer) {
        return (this->registerObserver(event, observer));
    }

    template<typename Observer>
    ListenerConnection connect(Observer &&observer) {
        return (this->registerObserver("", observer));
    }

    virtual void disconnect(ListenerConnection id) override;
    virtual void notifyAll() override;
    virtual void notify(const std::string &event) override;
    virtual void notify() override;
};


#endif //MVC_TEST_EVENTOBSERVER_HH
