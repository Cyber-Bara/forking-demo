#include "FreightCharges.h"

FreightCharges::FreightCharges(double baseRate, double weightRate, double volumeRate, double multiplier)
    : baseRatePerKm(baseRate), weightRate(weightRate), volumeRate(volumeRate), cargoTypeMultiplier(multiplier)
{
}

double FreightCharges::calculateCharges(double distance, double weight, double volume, std::string cargoType)
{
    double typeMultiplier = 1.0;

    // Adjust the multiplier based on cargo type
    if (cargoType == "fragile")
    {
        typeMultiplier = 1.5; // Higher multiplier for fragile cargo
    }
    else if (cargoType == "liquid")
    {
        typeMultiplier = 1.2; // Slightly higher for liquid cargo
    }
    else if (cargoType == "bulk")
    {
        typeMultiplier = 0.9; // Discount for bulk cargo
    }

    // Calculate the charge
    double totalCharges = (baseRatePerKm * distance) + (weightRate * weight) + (volumeRate * volume);
    totalCharges *= (typeMultiplier * cargoTypeMultiplier);

    return totalCharges;
}

void FreightCharges::displayRateInfo() const
{
    std::cout << "--- Freight Charges Rate Information ---" << std::endl;
    std::cout << "Base Rate per Km: $" << baseRatePerKm << std::endl;
    std::cout << "Weight Rate per Kg: $" << weightRate << std::endl;
    std::cout << "Volume Rate per Cubic Meter: $" << volumeRate << std::endl;
    std::cout << "Cargo Type Multiplier: " << cargoTypeMultiplier << std::endl;
}