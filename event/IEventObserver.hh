//
// Created by diguie_t on 11/26/2017.
//

#ifndef MVC_TEST_IEVENTOBSERVER_HH
#define MVC_TEST_IEVENTOBSERVER_HH

#include <string>
#include "../pattern/Observator.hpp"

class IEventObserver {
public:
    virtual ~IEventObserver() {}

    // todo force implementation
    /*template<typename Observer>
    virtual Observator::ListenerConnection connect(const std::string &event, Observer &&observer) = 0;
    template<typename Observer>
    virtual Observator::ListenerConnection connect(Observer &&observer) = 0;*/

    virtual void disconnect(ListenerConnection id) = 0;
    virtual void notify() = 0;
    virtual void notifyAll() = 0;
    virtual void notify(const std::string &event) = 0;
};

#endif //MVC_TEST_IEVENTOBSERVER_HH
