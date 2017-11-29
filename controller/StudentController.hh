//
// Created by diguie_t on 11/26/2017.
//

#ifndef MVC_TEST_STUDENTCONTROLLER_HH
#define MVC_TEST_STUDENTCONTROLLER_HH

#include <string>
#include "../model/StudentModel.hh"
#include "../view/StudentView.hh"
#include "../view/ViewHandler.hh"
#include "IBaseController.hh"

class StudentController : public IBaseController {
private:
	std::shared_ptr<ModelHandler> _modelHandler;
	std::shared_ptr<ViewHandler> _viewHandler;
	std::shared_ptr<StudentModel> _studentModel;
	std::shared_ptr<StudentView> _studentView;

public:
	StudentController();
	virtual ~StudentController();

	void setModelHandler(std::shared_ptr<ModelHandler> modelHandler) override;
	void setViewHandler(std::shared_ptr<ViewHandler> viewHandler) override;
};

#endif // MVC_TEST_STUDENTCONTROLLER_HH
