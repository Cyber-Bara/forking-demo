#include "Carrier.h"


// General Cargo Vessel class
class GeneralCargoVessel : public Carrier
{
public:
    GeneralCargoVessel(string n, double cap, double spd, string sz)
        : Carrier(n, cap, spd, sz, "General Cargo Vessel") {}
};


// Oil Tanker class
class OilTanker : public Carrier
{
public:
    OilTanker(string n, double cap, double spd, string sz)
        : Carrier(n, cap, spd, sz, "Oil Tanker") {}
};


// Bulk Carrier class
class BulkCarrier : public Carrier
{
public:
    BulkCarrier(string n, double cap, double spd, string sz)
        : Carrier(n, cap, spd, sz, "Bulk Carrier") {}
};


// Passenger Liner class
class PassengerLiner : public Carrier
{
public:
    PassengerLiner(string n, double cap, double spd, string sz)
        : Carrier(n, cap, spd, sz, "Passenger Liner") {}
};


// Container Ship class
class ContainerShip : public Carrier
{
public:
    ContainerShip(string n, double cap, double spd, string sz)
        : Carrier(n, cap, spd, sz, "Container Ship") {}
};

