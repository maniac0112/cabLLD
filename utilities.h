#pragma once 
#include <string> 

struct Location{
    int x_;
    int y_; 
    std::string toString(){
        return " (" + std::to_string(x_)+","+std::to_string(y_)+") "; 
    }
    Location(int x = 0, int y = 0): x_(x), y_(y){
    }
};

enum class Rating{
    OneStar,
    TwoStar,
    ThreeStar,
    FourStar,
    FiveStar,
};

enum class TripStatus{ 
    TripInitiated, 
    TripConfirmed,
    TripInProgress,
    TripEnded,
    StatusUnknown
};

inline std::string tripStatusToString(TripStatus status) {
    switch (status) {
        case TripStatus::TripInitiated:   return "Trip Initiated";
        case TripStatus::TripConfirmed:   return "Trip Confirmed";
        case TripStatus::TripInProgress:  return "Trip In Progress";
        case TripStatus::TripEnded:       return "Trip Ended";
        default:                         return "Status Unknown";
    }
}