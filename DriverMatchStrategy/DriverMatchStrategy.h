#pragma once

#include "../driver.h"
#include "../tripMetaData.h"
#include "../driverManager.h"

class DriverMatchStrategy{
public: 
    //has trip meta data and returns appropriate driver
    virtual Driver* getMatchedDriver(TripMetaData* trip_meta_data) = 0; 
};