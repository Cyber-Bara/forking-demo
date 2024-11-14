#include "Carrier.h"
#include <iostream>

Carrier::Carrier(std::string n, double cap, double spd, std::string sz, std::string dsg)
    : name(n), capacity(cap), speed(spd), size(sz), design(dsg), crew(nullptr)
{
}

Carrier::~Carrier()
{
    for (auto cargo : cargoList)
    {
        delete cargo;
    }
}

void Carrier::assignCrew(Crew* crewMember)
{
    crew = crewMember;
}

void Carrier::loadCargo(Cargo* cargo)
{
    if (cargo->getWeight() <= capacity * 1000) // Convert tons to kg
    {
        cargoList.push_back(cargo);
        capacity -= cargo->getWeight() / 1000; // Convert kg to tons
    }
    else
    {
        std::cout << "Not enough capacity to load this cargo!" << std::endl;
    }
}

std::string Carrier::getName() const
{
    return name;
}

void Carrier::displayCarrierInfo() const
{
    std::cout << "Carrier: " << name << std::endl;
    std::cout << "Remaining Capacity: " << capacity << " tons" << std::endl;
    std::cout << "Speed: " << speed << " knots" << std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout << "Design: " << design << std::endl;
    if (crew)
        crew->displayCrewInfo();
    else
        std::cout << "No crew assigned." << std::endl;
    std::cout << "--- Loaded Cargo ---" << std::endl;
    for (const auto& cargo : cargoList)
        cargo->displayCargoInfo();
}

// Derived class implementations
GeneralCargoVessel::GeneralCargoVessel(std::string n, double cap, double spd, std::string sz)
    : Carrier(n, cap, spd, sz, "General Cargo Vessel")
{
}

OilTanker::OilTanker(std::string n, double cap, double spd, std::string sz)
    : Carrier(n, cap, spd, sz, "Oil Tanker")
{
}

BulkCarrier::BulkCarrier(std::string n, double cap, double spd, std::string sz)
    : Carrier(n, cap, spd, sz, "Bulk Carrier")
{
}

PassengerLiner::PassengerLiner(std::string n, double cap, double spd, std::string sz)
    : Carrier(n, cap, spd, sz, "Passenger Liner")
{
}

ContainerShip::ContainerShip(std::string n, double cap, double spd, std::string sz)
    : Carrier(n, cap, spd, sz, "Container Ship")
{
}