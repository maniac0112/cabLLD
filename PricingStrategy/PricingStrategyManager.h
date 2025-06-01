#pragma once 

#include "PricingStrategy.h"
#include <mutex> 

class PricingStrategyManager{
public: 

    static PricingStrategyManager* getPricingStrategyManagerInstance(); 

    PricingStrategy* getPricingStrategy(TripMetaData* metadata);

private: 

    PricingStrategyManager() = default;
    static std::mutex mtx_; 
    static PricingStrategyManager* instance_; 
};