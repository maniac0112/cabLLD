#include "rider.h"

int Rider::id_counter_ = 0;

Rider::Rider(const std::string& name, Rating rating): 
    name_(name),
    rating_(rating),
    id_(id_counter_++)
{}

std::string Rider::getRiderName(){
    return name_; 
}

Rating Rider::getRiderRating(){
    return rating_; 
}