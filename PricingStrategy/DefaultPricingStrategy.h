#include "PricingStrategy.h"

class DefaultPricingStrategy : public PricingStrategy{
public:
    double getPrice(TripMetaData* meta_data) override {
        return 100.0; 
    }
};
