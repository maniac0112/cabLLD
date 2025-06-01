#pragma once

#include <string>
#include <unordered_map>
#include <mutex>

#include "driver.h"

class DriverManager{
public:
    void addDriver(Driver* driver); // Add code to make this thread safe as well :)

    Driver* getDriver(const std::string& username); // Add code to make this thread safe as well :)

    static DriverManager* getDriverManagerInstance();

    std::unordered_map<std::string, Driver*>  getDriverMap();
private:

    DriverManager() = default;
    std::unordered_map<std::string, Driver*> DriverMap_; 
    static std::mutex mtx_; 
    static DriverManager* instance_;
};