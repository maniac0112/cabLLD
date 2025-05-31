#pragma once 

#include <unordered_map>
#include <mutex> 

#include "trip.h"
#include "tripMetaData.h"
#include "utilities.h"
#include "riderManager.h"
#include "driverManager.h"

class TripManager{
public: 

    static TripManager* getTripManagerInstance();
    
    void createTrip(Rider* rider, Location* source, Location* distance);

    std::unordered_map<uint32_t, Trip*> getTripMap();

private: 
    TripManager();
    static TripManager* instance_; 
    static std::mutex mtx_;
    RiderManager* riderManager_;
    DriverManager* driverManager_; 
    std::unordered_map<uint32_t, Trip*> TripMap; 
    std::unordered_map<uint32_t, TripMetaData*> TripMetaDataMap; 
};