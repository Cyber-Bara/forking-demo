#pragma once

#include "FreightCharges.h"   // Assuming FreightCharges class is defined
#include "CustomDuty.h"       // Assuming CustomDuty class is defined
#include "Cargo.h"            // Assuming Cargo class is defined
#include <string>
#include <iostream>

class TotalCostCalculator : public FreightCharges, public CustomDuty {
public:
    // Constructor to initialize both base classes
    TotalCostCalculator(double baseRate, double weightRate, double volumeRate, double typeMultiplier,
                        double dutyRate, std::string destinationCountry, double additionalFee);

    // Method to calculate the total cost
    double calculateTotalCost(double distance, const Cargo* cargo, std::string cargoType);

    // Method to display the detailed breakdown of customs duty for a cargo
    void displayDutyDetails(const Cargo* cargo) const;

    // Display the rates and duties information
    void displayRatesAndDuties() const;

    // Method to display the total cost breakdown
    void displayTotalCost(double distance, const Cargo* cargo, std::string cargoType);
};
