#pragma once

#include<string>
#include<iostream>
#include "Crew.h"
#include "Cargo.h"


using namespace std;

class Carrier
{
protected:
    string name;
    double capacity;  // Capacity in tons
    double speed;     // Speed in knots
    string size;      // Size of the carrier
    string design;    // Design type (e.g., container ship, bulk carrier)
    vector<Cargo*> cargoList;
    Crew* crew; // Pointer to assigned crew member

public:
    Carrier(string n, double cap, double spd, string sz, string dsg)
    {
        this->name = n;
        this->capacity = cap;
        this->speed = spd;
        this->size = sz;
        this->design = dsg;
        this->crew = nullptr; // Initialize without crew
    }


    void assignCrew(Crew* crewMember)
    {
        crew = crewMember;
    }


    void loadCargo(Cargo* cargo)
    {
        if (cargo->getWeight() <= capacity * 1000) // Convert tons to kg
        {
            cargoList.push_back(cargo);
            capacity -= cargo->getWeight() / 1000; // Convert kg to tons
        }
        else
        {
            cout << "Not enough capacity to load this cargo!" << endl;
        }
    }


    string getName() const { return name; }


    void displayCarrierInfo() const
    {
        cout << "Carrier: " << name << endl;
        cout << "Remaining Capacity: " << capacity << " tons" << endl;
        cout << "Speed: " << speed << " knots" << endl;
        cout << "Size: " << size << endl;
        cout << "Design: " << design << endl;
        if (crew) crew->displayCrewInfo();
        else cout << "No crew assigned." << endl;
        cout << "--- Loaded Cargo ---" << endl;
        for (const auto& cargo : cargoList) cargo->displayCargoInfo();
    }
};

