#include "PricingStrategyManager.h"
#include "DefaultPricingStrategy.h"

std::mutex PricingStrategyManager::mtx_{};
PricingStrategyManager* PricingStrategyManager::instance_ = nullptr;

PricingStrategyManager* PricingStrategyManager::getPricingStrategyManagerInstance(){
    if (instance_ == nullptr){
        mtx_.lock();
        if (instance_ == nullptr){
            instance_ = new PricingStrategyManager();
        }
        mtx_.unlock();
    }
    return instance_;
}

PricingStrategy* PricingStrategyManager::getPricingStrategy(TripMetaData* meta_data){
    //return some strategy based on meta_data
    return new DefaultPricingStrategy; 
}