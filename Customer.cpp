#include "Customer.h"

Customer::Customer(std::string name, std::string contact)
{
    this->customerName = name;
    this->contactInfo = contact;
}

void Customer::addShipment(Shipment* shipment)
{
    shipmentHistory.push_back(shipment);
}

void Customer::displayCustomerInfo() const
{
    std::cout << "Customer Name: " << customerName << std::endl;
    std::cout << "Contact Info: " << contactInfo << std::endl;
    std::cout << "--- Shipment History ---" << std::endl;
    
    for (const auto& shipment : shipmentHistory)
    {
        shipment->displayShipmentInfo();
    }
}
