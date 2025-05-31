#pragma once

#include "../tripMetaData.h"

class PricingStrategy{
public: 
    virtual double getPrice(TripMetaData* trip_meta_data) = 0; 
};