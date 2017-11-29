//
// Created by diguie_t on 11/26/2017.
//

#ifndef MVC_TEST_DATAHANDLER_HPP
#define MVC_TEST_DATAHANDLER_HPP

#include <unordered_map>

template <typename Value, typename Data>
class DataHandler {
protected:
    std::unordered_map<Value, Data> _data; // class that inherit must handle the destruction of the map

    std::pair<bool, Data> getData(const Value &value) { // todo use boost::optional instead
        auto result = this->_data.find(value);
        if (result != this->_data.end()) {
            return (std::make_pair(true, result->second));
        }
        return (std::make_pair(false, Data()));
    }
};

#endif //MVC_TEST_DATAHANDLER_HPP
