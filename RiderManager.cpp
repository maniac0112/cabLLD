#include "riderManager.h"

RiderManager* RiderManager::instance_ = nullptr; 
std::mutex RiderManager::mtx_{};

RiderManager* RiderManager::getRiderManagerInstance(){
    if (instance_ == nullptr){
        mtx_.lock();
        if (instance_ == nullptr){
            instance_ = new RiderManager();
        }
        mtx_.unlock();
    }
    return instance_;
}

void RiderManager::addRider(Rider* Rider){
    std::string Rider_name = Rider->getRiderName();
    RiderMap_[Rider_name] = Rider; 
}

Rider* RiderManager::getRider(const std::string& Rider_name){
    return RiderMap_[Rider_name];
}