//
// Created by diguie_t on 11/26/2017.
//

#ifndef MVC_TEST_IBASECONTROLLER_HH
#define MVC_TEST_IBASECONTROLLER_HH

#include <unordered_map>
#include <vector>
#include <string>
#include "../model/ModelHandler.hh"
#include "../view/ViewHandler.hh"

class IBaseController {
public:
    virtual ~IBaseController() {}
    IBaseController() {}
    IBaseController(const IBaseController &) {}
    IBaseController & operator = (const IBaseController &) {return (*this);}
    virtual void setModelHandler(std::shared_ptr<ModelHandler> modelHandler) = 0;
    virtual void setViewHandler(std::shared_ptr<ViewHandler> viewHandler) = 0;
};

#endif //MVC_TEST_IBASECONTROLLER_HH
