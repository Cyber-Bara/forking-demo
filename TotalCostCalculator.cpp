#include "TotalCostCalculator.h"

TotalCostCalculator::TotalCostCalculator(double baseRate, double weightRate, double volumeRate, double typeMultiplier,
                                         double dutyRate, std::string destinationCountry, double additionalFee)
    : FreightCharges(baseRate, weightRate, volumeRate, typeMultiplier),
      CustomDuty(dutyRate, destinationCountry, additionalFee) {}

double TotalCostCalculator::calculateTotalCost(double distance, const Cargo* cargo, std::string cargoType)
{
    double shippingCost = calculateCharges(distance, cargo->getWeight(), cargo->getVolume(), cargoType);
    double dutyCost = calculateDuty(cargo);
    return shippingCost + dutyCost;
}

void TotalCostCalculator::displayDutyDetails(const Cargo* cargo) const
{
    CustomDuty::displayDutyDetails(cargo);
}

void TotalCostCalculator::displayRatesAndDuties() const
{
    FreightCharges::displayRateInfo();
    std::cout << "--- Customs Duty Information ---" << std::endl;
    std::cout << "Destination Country: " << CustomDuty::getDestinationCountry() << std::endl;
}

void TotalCostCalculator::displayTotalCost(double distance, const Cargo* cargo, std::string cargoType)
{
    double shippingCost = calculateCharges(distance, cargo->getWeight(), cargo->getVolume(), cargoType);
    double dutyCost = calculateDuty(cargo);
    double totalCost = shippingCost + dutyCost;

    std::cout << "--- Total Cost Breakdown ---" << std::endl;
    std::cout << "Cargo ID: " << cargo->getId() << std::endl;
    std::cout << "Shipping Cost: $" << shippingCost << std::endl;
    std::cout << "Customs Duty: $" << dutyCost << std::endl;
    std::cout << "Total Cost: $" << totalCost << std::endl;
}
