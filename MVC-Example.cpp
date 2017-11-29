//
// Created by diguie_t on 11/26/2017.
//

#include <iostream>
#include <memory>
#include "controller/StudentController.hh"
#include "view/StudentViewTwo.hh"
#include "controller/ControllerHandler.hh"

int main() {
	std::shared_ptr<ModelHandler> modelHandler(new ModelHandler());
    std::shared_ptr<ViewHandler> viewHandler(new ViewHandler());
    ControllerHandler controllerHandler(modelHandler, viewHandler);

	std::shared_ptr<StudentView> view = viewHandler->getView<StudentView>("student_1");
	auto studentModel = modelHandler->getModel<StudentModel>("student");
	std::shared_ptr<StudentViewTwo> viewtwo = viewHandler->getView<StudentViewTwo>("student_2");

	studentModel->setName("John");
	studentModel->setId("42");
	view->onFormSubmit();
	viewtwo->addStudent(*studentModel);
	studentModel->setName("Doe");
    return (0);
}

