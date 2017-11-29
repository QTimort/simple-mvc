cmake_minimum_required(VERSION 3.9)
project(mvc_test)

set(CMAKE_CXX_STANDARD 11)

set(MVC_SRC
        MVC-Example.cpp
        DataHandler.hpp
        pattern/Observator.hpp
        view/StudentView.cpp
        view/StudentView.hh
        view/StudentViewTwo.cpp
        view/StudentViewTwo.hh
        view/ABaseView.cpp
        view/ABaseView.hh
        controller/IBaseController.hh
        controller/ControllerHandler.cpp
        controller/ControllerHandler.hh
        controller/ControllerFactory.hhp
        controller/IControllerFactory.hh
        controller/StudentController.cpp
        controller/StudentController.hh
        model/ModelHandler.cpp
        model/ModelHandler.hh
        model/StudentModel.cpp
        model/StudentModel.hh
        event/IEventObserver.hh
        event/EventObserver.cpp
        event/EventObserver.hh
        model/ABaseModel.cpp
        model/ABaseModel.hh
        view/ViewHandler.cpp
        view/ViewHandler.hh
        )

add_executable(mvc_test ${MVC_SRC})