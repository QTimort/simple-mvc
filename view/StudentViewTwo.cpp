//
// Created by diguie_t on 11/26/2017.
//

#include <iostream>
#include "StudentViewTwo.hh"

StudentViewTwo::StudentViewTwo() {
    this->registerObserver("update_student", [&] () {
        std::cout << "[StudentViewTwo] Self Observer \"student_update\" triggered." << std::endl;
        return (true);
    });
}

const std::string &StudentViewTwo::getViewPath() const {
    return ("");
}

void StudentViewTwo::addStudent(StudentModel &studentModel) {
    std::cout << "[StudentViewTwo] Added new student to the view." << std::endl;
    std::cout << "[StudentViewTwo] id: " << studentModel.getId() << std::endl;
    std::cout << "[StudentViewTwo] name: " << studentModel.getName() << std::endl;
    std::cout << std::endl;

    studentModel.connect([&]() {
        std::cout << "[StudentViewTwo] Student Model Updated, view is applying changes." << std::endl;
        this->notify();
        return (false);
    });
}
