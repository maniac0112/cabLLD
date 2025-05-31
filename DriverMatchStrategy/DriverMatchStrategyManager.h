#include "DriverMatchStrategy.h"
#include <mutex> 

class DriverMatchStrategyManager{
public: 
    //return a DriverMatchStrategy !! 
    static DriverMatchStrategyManager* getDriverMatchStrategyManagerInstance(); 

    DriverMatchStrategy* getDriverMatchStrategy(TripMetaData* metadata);

private: 

    DriverMatchStrategyManager();
    static std::mutex mtx_; 
    static DriverMatchStrategyManager* instance_; 
};