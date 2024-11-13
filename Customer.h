#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Shipment.h"  // Assuming Shipment class is defined

class Customer {
private:
    std::string customerName;
    std::string contactInfo;
    std::vector<Shipment*> shipmentHistory;

public:
    Customer(std::string name, std::string contact);
    
    void addShipment(Shipment* shipment);
    void displayCustomerInfo() const;
};
