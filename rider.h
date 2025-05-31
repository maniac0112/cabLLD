#pragma once 
#include <string> 
#include "utilities.h"

class Rider {
public: 
    Rider(const std::string& name = "Default Rider", Rating rating = Rating::FiveStar);

    std::string getRiderName();

    Rating getRiderRating();

private: 
    static int id_counter_; 
    int id_; 
    std::string name_; 
    Rating rating_; 
};