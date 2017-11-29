//
// Created by diguie_t on 11/26/2017.
//

#include <string>
#include "StudentModel.hh"

const std::string& StudentModel::getName() const {
	return this->_name;
}

void StudentModel::setName(const std::string& name) {
	this->_name = name;
    this->notify();
}

const std::string& StudentModel::getId() const {
	return _id;
}

void StudentModel::setId(const std::string &id) {
	this->_id = id;
    this->notify("event");
}

StudentModel::StudentModel() : ABaseModel() {
	this->_id = "Default Id";
	this->_name = "Default Name";
}


