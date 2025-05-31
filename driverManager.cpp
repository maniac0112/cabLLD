#include "driverManager.h"

DriverManager* DriverManager::instance_ = nullptr; 
std::mutex DriverManager::mtx_{};

void DriverManager::addDriver(Driver* driver){
    std::string driver_name = driver->getDriverName();
    DriverMap_[driver_name] = driver; 
}

Driver* DriverManager::getDriver(const std::string& driver_name){
    return DriverMap_[driver_name];
}

DriverManager* DriverManager::getDriverManagerInstance(){
    if (instance_ == nullptr){
        mtx_.lock();
        if (instance_ == nullptr){
            instance_ = new DriverManager();
        }
        mtx_.unlock();
    }

    return instance_;
}

std::unordered_map<std::string, Driver*>  DriverManager::getDriverMap(){
    return DriverMap_;
}