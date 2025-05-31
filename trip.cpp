#include <iostream>
#include "trip.h"

std::atomic<uint32_t> Trip::nextID_{0};

Trip::Trip(Rider* rider, Driver* driver, Location* source, Location* destination, TripStatus status, double price, PricingStrategy* pricing_strategy, DriverMatchStrategy* driver_match_strategy):
    rider_(rider),
    driver_(driver),
    source_(source),
    destination_(destination),
    status_(status),
    price_(price),
    pricingStrategy_(pricing_strategy),
    driverMatchStrategy(driver_match_strategy),
    tripID_(nextID_.load())
{
    nextID_.fetch_add(1);
}

int Trip::getTripId(){
    return tripID_;
}

void Trip::printTrip(){
    
    //Calling this from Multiple Threads would result in undefined behavior and weird mix ups :)

    std::cout<<"\n----------- Printing Trip Summary ----------- \n";
    std::cout << "Trip ID  : " << tripID_ << "\n";
    if (rider_)
        std::cout << "Rider : " << rider_->getRiderName() << "\n";

    if (driver_)
        std::cout << "Driver : " << driver_->getDriverName() << "\n";

    if (source_)
        std::cout << "Source : " << source_->toString() << "\n";

    if (destination_)
        std::cout << "Destination : " << destination_->toString() << "\n";

    std::cout << "Status  : " << tripStatusToString(status_) << "\n";
    std::cout << "Price  : " << price_ << "\n";
}