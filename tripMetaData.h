#pragma once 

#include "utilities.h"

//This is a lightweight Trip Object used by Trip Manager for driver matching and pricing
class TripMetaData{
public: 

    TripMetaData(Location* source, Location* destination, Rating rider_rating); 
    Rating getRiderRating();
    Rating getDriverRating();
    void setDriverRating(Rating driver_rating);

private: 
    Location* source_; 
    Location* destination_; 
    Rating riderRating_;
    Rating driverRating_; 
}; 