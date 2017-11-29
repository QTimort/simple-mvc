//
// Created by diguie_t on 11/26/2017.
//

#include <iostream>
#include "StudentView.hh"

StudentView::StudentView() {

}

void StudentView::onFormSubmit() {
    this->_form.age = 1337;
    this->_form.name = "Leet";
    std::cout << "[StudentView] form has been submitted." << std::endl;
    this->notify("form_submit");
}

const std::string &StudentView::getViewPath() const {
    return ("student.html");
}

const StudentForm &StudentView::getForm() const {
    return (this->_form);
}

StudentForm::StudentForm() {
    this->name = "No Name";
    this->age = -1;
}
