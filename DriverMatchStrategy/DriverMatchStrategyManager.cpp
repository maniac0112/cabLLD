#include "DriverMatchStrategyManager.h"
#include "DefaultDriverMatchStrategy.h"

std::mutex DriverMatchStrategyManager::mtx_{};
DriverMatchStrategyManager* DriverMatchStrategyManager::instance_ = nullptr;

DriverMatchStrategyManager* DriverMatchStrategyManager::getDriverMatchStrategyManagerInstance(){
    if (instance_ == nullptr){
        mtx_.lock();
        if (instance_ == nullptr){
            instance_ = new DriverMatchStrategyManager();
        }
        mtx_.unlock();
    }
    return instance_;
}

DriverMatchStrategy* DriverMatchStrategyManager::getDriverMatchStrategy(TripMetaData* meta_data){
    //return some strategy based on meta_data
    return new DefaultDriverMatchStrategy; 
}