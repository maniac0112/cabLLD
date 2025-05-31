#include "tripMetaData.h"

TripMetaData::TripMetaData(Location* source, Location* destination, Rating rider_rating):
    source_(source),
    destination_(destination),
    riderRating_(rider_rating)
{
}

Rating TripMetaData::getRiderRating(){
    return riderRating_;
}

Rating TripMetaData::getDriverRating(){
    return driverRating_;
}

void TripMetaData::setDriverRating(Rating rating){
    driverRating_ = rating; 
}