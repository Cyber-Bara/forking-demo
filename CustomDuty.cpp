#include "CustomDuty.h"
#include <iostream>

CustomDuty::CustomDuty(double rate, std::string dest, double fee)
    : dutyRate(rate), destinationCountry(dest), additionalFee(fee)
{
}

double CustomDuty::calculateDuty(const Cargo *cargo) const
{
    double basicDuty = (cargo->getValue() * dutyRate) / 100;
    double totalDuty = basicDuty + additionalFee;
    return totalDuty;
}

void CustomDuty::displayDutyDetails(const Cargo *cargo) const
{
    std::cout << "--- Custom Duty Details ---" << std::endl;
    std::cout << "Destination Country: " << destinationCountry << std::endl;
    std::cout << "Duty Rate: " << dutyRate << "%" << std::endl;
    std::cout << "Additional Fee: $" << additionalFee << std::endl;
    std::cout << "Calculated Duty for Cargo ID " << cargo->getId() << ": $" << calculateDuty(cargo) << std::endl;
}

std::string CustomDuty::getDestinationCountry() const
{
    return destinationCountry;
}

void CustomDuty::setDutyRate(double rate)
{
    dutyRate = rate;
}

void CustomDuty::setAdditionalFee(double fee)
{
    additionalFee = fee;
}