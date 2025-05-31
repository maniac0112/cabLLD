#include "driver.h"

int Driver::id_counter_ = 0;

Driver::Driver(const std::string& name, Rating rating): 
    name_(name),
    rating_(rating),
    id_(id_counter_++)
{}

std::string Driver::getDriverName(){
    return name_; 
}

Rating Driver::getDriverRating(){
    return rating_; 
}