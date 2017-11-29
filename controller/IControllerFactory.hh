//
// Created by diguie_t on 11/26/2017.
//

#ifndef MVC_TEST_ICONTROLLERFACTORY_HH
#define MVC_TEST_ICONTROLLERFACTORY_HH

#include <memory>
#include "IBaseController.hh"

class IControllerFactory {
public:
    virtual ~IControllerFactory() {}
    virtual std::shared_ptr<IBaseController> build(std::shared_ptr<ModelHandler> modelHandler, std::shared_ptr<ViewHandler> viewHandler) = 0;
};

#endif //MVC_TEST_ICONTROLLERFACTORY_HH
