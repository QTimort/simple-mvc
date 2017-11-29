//
// Created by diguie_t on 11/26/2017.
//

#include "StudentController.hh"
#include "ControllerFactory.hhp"
#include "ControllerHandler.hh"

std::shared_ptr<IControllerFactory> ControllerHandler::getRouteControllerFactory(const std::string &route) {
    auto pair = this->getData(route);
    if (pair.first) {
        return (pair.second);
    }
    return (nullptr);
}

void ControllerHandler::changeRoute(const std::string &baseRoute, const std::string &subRoute) {
    std::shared_ptr<IControllerFactory> pFactory = this->getRouteControllerFactory(baseRoute);
    if (pFactory == nullptr) {
        std::cerr << "invalid route: " << baseRoute << std::endl;
    }
    this->_currentController.reset();
    this->_currentController = nullptr;
    this->_curBaseRoute = baseRoute;
    this->_curSubRoute = subRoute;
    this->_currentController = pFactory->build(_modelHandler, _viewHandler);
}

ControllerHandler::ControllerHandler(std::shared_ptr<ModelHandler> modelHandler, std::shared_ptr<ViewHandler> viewHandler) {
    this->_modelHandler = modelHandler;
    this->_viewHandler = viewHandler;
    this->_currentController = nullptr;
    this->_data = {
            {"/", std::shared_ptr<ControllerFactory<StudentController>>(new ControllerFactory<StudentController>())}
    };
    this->changeRoute("/", "");
}
