//
// Created by diguie_t on 11/28/2017.
//

#ifndef MVC_TEST_VIEWHANDLER_HH
#define MVC_TEST_VIEWHANDLER_HH

#include <string>
#include <memory>
#include "ABaseView.hh"
#include "../DataHandler.hpp"

class ViewHandler : public DataHandler<std::string, std::shared_ptr<ABaseView>> {
public:
    ViewHandler();

    template<typename View>
    std::shared_ptr<View> getView(const std::string &name) {

        auto pair = this->getData(name);
        if (pair.first) {
            return (std::dynamic_pointer_cast<View>(pair.second));
        }
        return (std::shared_ptr<View>(nullptr));
    }
};


#endif //MVC_TEST_VIEWHANDLER_HH
