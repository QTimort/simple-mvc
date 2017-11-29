//
// Created by diguie_t on 11/26/2017.
//

#ifndef MVC_TEST_CONTROLLERHANDLER_HH
#define MVC_TEST_CONTROLLERHANDLER_HH

#include <unordered_map>
#include "IBaseController.hh"
#include "IControllerFactory.hh"
#include "../DataHandler.hpp"

class ControllerHandler : public DataHandler<std::string, std::shared_ptr<IControllerFactory>> {
private:
    std::string _curBaseRoute;
    std::string _curSubRoute;
    std::shared_ptr<IBaseController> _currentController;
    std::shared_ptr<ModelHandler> _modelHandler;
    std::shared_ptr<ViewHandler> _viewHandler;

    std::shared_ptr<IControllerFactory> getRouteControllerFactory(const std::string &route);

public:
    ControllerHandler() = delete;
    explicit ControllerHandler(std::shared_ptr<ModelHandler> modelHandler, std::shared_ptr<ViewHandler> viewHandler);
    void changeRoute(const std::string &route, const std::string &subRoute);
};


#endif //MVC_TEST_CONTROLLERHANDLER_HH
