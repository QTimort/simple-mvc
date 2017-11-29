//
// Created by diguie_t on 11/26/2017.
//

#ifndef MVC_TEST_STUDENTVIEWTWO_HH
#define MVC_TEST_STUDENTVIEWTWO_HH

#include "../model/StudentModel.hh"
#include "ABaseView.hh"

class StudentViewTwo : public ABaseView {
public:
	StudentViewTwo();

	void addStudent(StudentModel &studentModel);
    const std::string &getViewPath() const override;
};

#endif // MVC_TEST_STUDENTVIEWTWO_HH
