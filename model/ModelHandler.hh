//
// Created by diguie_t on 11/26/2017.
//

#ifndef MVC_TEST_MODELHANDLER_HH
#define MVC_TEST_MODELHANDLER_HH

#include <unordered_map>
#include <memory>
#include "../DataHandler.hpp"
#include "ABaseModel.hh"

class ModelHandler : public DataHandler<std::string, std::shared_ptr<ABaseModel>> {
public:
    ModelHandler();

    template<typename Model>
    std::shared_ptr<Model> getModel(const std::string &name) {

        auto pair = this->getData(name);
        if (pair.first) {
            return (std::dynamic_pointer_cast<Model>(pair.second));
        }
        return (std::shared_ptr<Model>(nullptr));
    }
};


#endif //MVC_TEST_MODELHANDLER_HH
