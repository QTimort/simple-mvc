//
// Created by diguie_t on 11/26/2017.
//

#include "StudentModel.hh"
#include "ModelHandler.hh"

ModelHandler::ModelHandler() {
    this->_data.insert({"student", std::shared_ptr<ABaseModel>(new StudentModel())});
}