#pragma once

#include <string>
#include <unordered_map>
#include <mutex>

#include "rider.h"

class RiderManager{
public:
    void addRider(Rider* rider); // Add code to make this thread safe as well :)
    
    Rider* getRider(const std::string& username); // Add code to make this thread safe as well :)

    static RiderManager* getRiderManagerInstance();
    
private:

    RiderManager() = default;
    std::unordered_map<std::string, Rider*> RiderMap_; 
    static std::mutex mtx_; 
    static RiderManager* instance_;
};