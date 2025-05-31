#pragma once

#include <atomic>
#include "utilities.h"
#include "driver.h"
#include "rider.h"
#include "DriverMatchStrategy/DriverMatchStrategy.h"
#include "PricingStrategy/PricingStrategy.h"


class Trip{
public: 

    Trip(Rider* rider, Driver* Driver, Location* source, Location* destination, TripStatus status, double price, PricingStrategy* pricing_strategy, DriverMatchStrategy* driver_match_strategy);
    
    int getTripId();
    
    void printTrip();

private: 
    Rider* rider_; 
    Driver* driver_;
    Location* source_;
    Location* destination_;
    TripStatus status_; 
    uint32_t tripID_;
    double price_; 
    PricingStrategy* pricingStrategy_;
    DriverMatchStrategy* driverMatchStrategy;
    static std::atomic<uint32_t> nextID_; 
};