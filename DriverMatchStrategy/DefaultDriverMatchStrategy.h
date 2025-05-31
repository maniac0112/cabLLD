#pragma once

#include <iostream>
#include "DriverMatchStrategy.h"

class DefaultDriverMatchStrategy : public DriverMatchStrategy {

public: 
    Driver* getMatchedDriver(TripMetaData* meta_data) override {
        DriverManager* driverManagerInstance = DriverManager::getDriverManagerInstance();
        if ((driverManagerInstance->getDriverMap()).size()==0){
            std::cout<<" No nearby drivers! \n";
        }

        return driverManagerInstance->getDriverMap().begin()->second;
        //return the first available driver 
    }
};