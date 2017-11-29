//
// Created by diguie_t on 11/26/2017.
//

#include <string>
#include "../model/StudentModel.hh"
#include "../view/StudentViewTwo.hh"
#include "StudentController.hh"

StudentController::~StudentController() {
}

StudentController::StudentController() {

}

void StudentController::setModelHandler(std::shared_ptr<ModelHandler> modelHandler) {
	this->_modelHandler = modelHandler;
	this->_studentModel = this->_modelHandler->getModel<StudentModel>("student");
	this->_studentModel->connect([&] () {
            std::cout << "[StudentController] StudentModel has been updated." << std::endl;
            std::cout << "[StudentController] StudentModel id: " << this->_studentModel->getId() << std::endl;
            std::cout << "[StudentController] StudentModel name: " << this->_studentModel->getName() << std::endl;
            std::cout << std::endl;
		return true;
	});
}

void StudentController::setViewHandler(std::shared_ptr<ViewHandler> viewHandler) {
	this->_viewHandler = viewHandler;
	this->_studentModel->connect([&] () {
		std::cout << "[StudentController]	StudentModel has been updated" << std::endl;
		std::cout << "[StudentController]	Updating the StudentViewTwo" << std::endl;
		this->_viewHandler->getView<StudentViewTwo>("student_2")->notify("update_student");
		return (false);
	});

	this->_studentView = this->_viewHandler->getView<StudentView>("student_1");
	this->_studentView->connect("form_submit", [&] () {
		std::cout << "[StudentController] Student 1 View Form has been submit." << std::endl;
		const auto &form = this->_studentView->getForm();
		std::cout << "[StudentController] Student Form name: " << form.name << std::endl;
		std::cout << "[StudentController] Student Form age: " << std::to_string(form.age) << std::endl;
		std::cout << std::endl;
		this->_studentModel->setName(form.name);
		this->_studentModel->setId(std::to_string(form.age)); // yes id != age, but it's just an example !
        return (true);
    });
}
