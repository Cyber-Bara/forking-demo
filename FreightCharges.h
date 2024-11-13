#pragma once

#include <string>
#include <iostream>

class FreightCharges
{
private:
    double baseRatePerKm;       // Base rate per kilometer
    double weightRate;          // Rate per kilogram of cargo weight
    double volumeRate;          // Rate per cubic meter of cargo volume
    double cargoTypeMultiplier; // Multiplier based on cargo type (e.g., fragile, liquid)

public:
    FreightCharges(double baseRate, double weightRate, double volumeRate, double multiplier);
    double calculateCharges(double distance, double weight, double volume, std::string cargoType);
    void displayRateInfo() const;
};