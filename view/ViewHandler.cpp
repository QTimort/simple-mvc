//
// Created by diguie_t on 11/28/2017.
//

#include "ViewHandler.hh"
#include "StudentView.hh"
#include "StudentViewTwo.hh"

ViewHandler::ViewHandler() {
    this->_data = {
            {"student_1", std::shared_ptr<ABaseView>(new StudentView())},
            {"student_2", std::shared_ptr<ABaseView>(new StudentViewTwo())}
    };
}
