//
// Created by diguie_t on 11/26/2017.
//

#ifndef MVC_TEST_STUDENT_MODEL_HH
#define MVC_TEST_STUDENT_MODEL_HH

#include <string>
#include <functional>
#include <list>
#include "ABaseModel.hh"

class StudentModel : public ABaseModel {
private:
    std::string _id;
    std::string _name;

public:
    StudentModel();

    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getId() const;
    void setId(const std::string &id);
};

#endif // MVC_TEST_STUDENT_MODEL_HH
