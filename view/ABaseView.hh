//
// Created by diguie_t on 11/28/2017.
//

#ifndef MVC_TEST_ABASEVIEW_HH
#define MVC_TEST_ABASEVIEW_HH

#include "../event/EventObserver.hh"

class ABaseView : public EventObserver {
public:
    virtual const std::string &getViewPath() const = 0;
};


#endif //MVC_TEST_ABASEVIEW_HH
