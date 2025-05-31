#pragma once 
#include <string> 
#include "utilities.h"

class Driver {
public: 
    Driver(const std::string& name = "Default Rider", Rating rating = Rating::FiveStar);

    std::string getDriverName();

    Rating getDriverRating();

    //Can Add Code for Vehicle Number Later 

private: 
    static int id_counter_; 
    int id_; 
    std::string name_; 
    Rating rating_; 
};