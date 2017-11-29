//
// Created by diguie_t on 11/26/2017.
//

#ifndef MVC_TEST_STUDENTVIEW_HH
#define MVC_TEST_STUDENTVIEW_HH

#include "../model/StudentModel.hh"
#include "ABaseView.hh"

class StudentForm {
public:
	std::string name;
	int age;

public:
	StudentForm();
};

class StudentView : public ABaseView {
private:
	StudentForm _form;
public:
	StudentView();
    const std::string &getViewPath() const override;
    void onFormSubmit();
	const StudentForm &getForm() const;
};

#endif // MVC_TEST_STUDENTVIEW_HH
