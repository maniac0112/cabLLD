#include <iostream>
#include <string>
#include "driverManager.h"
#include "riderManager.h"
#include "tripManager.h"
#include "PricingStrategy/PricingStrategy.h"
#include "DriverMatchStrategy/DriverMatchStrategy.h"

int main() {
    // Create drivers
    DriverManager* driverManager = DriverManager::getDriverManagerInstance();
    
    driverManager->addDriver(new Driver("alice", Rating::FiveStar));
    driverManager->addDriver(new Driver("Bob", Rating::ThreeStar));

    Rider* rider1 = new Rider("Charlie", Rating::FourStar);
    Location* src = new Location(0,0); 
    Location* dst = new Location(10,20); 
    // Create riders
    RiderManager* riderManager = RiderManager::getRiderManagerInstance();
    riderManager->addRider(rider1);

    
    // Book a trip
    TripManager* tripManager = TripManager::getTripManagerInstance();
    tripManager->createTrip(
        rider1,
        src,
        dst
    );

    std::unordered_map<uint32_t, Trip*> tripmap = tripManager->getTripMap();
    for (auto &trips: tripmap){
        trips.second->printTrip();
    }

    return 0;
}

/*
clang++ -std=c++20 \
    uber.cpp driver.cpp rider.cpp trip.cpp tripManager.cpp tripMetaData.cpp \
    driverManager.cpp riderManager.cpp \
    PricingStrategy/DefaultPricingStrategy.cpp \
    DriverMatchStrategy/NearestDriverMatchStrategy.cpp \
    -o uber.out
*/