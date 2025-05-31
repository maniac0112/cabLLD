#include "tripManager.h"
#include "DriverMatchStrategy/DriverMatchStrategyManager.h"
#include "PricingStrategy/PricingStrategyManager.h"

TripManager* TripManager::instance_ = nullptr; 
std::mutex TripManager::mtx_{};

TripManager* TripManager::getTripManagerInstance(){
    if (instance_ == nullptr){
        mtx_.lock();
        if (instance_ == nullptr){
            instance_ = new TripManager();
        }
        mtx_.unlock();
    }
    return instance_;
}

std::unordered_map<uint32_t, Trip*> TripManager::getTripMap(){
    return TripMap;
}

void TripManager::createTrip(Rider* rider, Location* source, Location* destination){
    TripMetaData* meta_data = new TripMetaData(source,destination, rider->getRiderRating());
    
    //get driver match strategy manager 
    DriverMatchStrategyManager* driver_match_strategy_manager = DriverMatchStrategyManager::getDriverMatchStrategyManagerInstance();
    //get appropriate driver strategy 
    DriverMatchStrategy* driver_match_strategy = driver_match_strategy_manager->getDriverMatchStrategy(meta_data);
    //get appropriate driver match 
    Driver* driver = driver_match_strategy->getMatchedDriver(meta_data);

    //Now set this in trip meta data 
    meta_data->setDriverRating(driver->getDriverRating());

    //get pricing strategy manager 
    PricingStrategyManager* pricing_strategy_manager = PricingStrategyManager::getPricingStrategyManagerInstance();
    //get appropriate pricing strategy 
    PricingStrategy* pricing_strategy = pricing_strategy_manager->getPricingStrategy(meta_data);
    //get appropriate price based on this strategy 
    double price = pricing_strategy->getPrice(meta_data); 

    //Create a trip instance for this 
    Trip* trip = new Trip(rider,driver, source, destination, TripStatus::TripConfirmed, price, pricing_strategy, driver_match_strategy);
    TripMap[trip->getTripId()] = trip; 
    
    //May use meta data for safer analytics in future? 
    TripMetaDataMap[trip->getTripId()] = meta_data;
}