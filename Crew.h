#pragma once

#include <string>
#include <iostream>

class Crew
{
private:
    std::string name;
    std::string position;
    int experience; // in years

public:
    Crew(std::string n, std::string pos, int exp);

    std::string getName() const;
    std::string getPosition() const;
    int getExperience() const;
    void displayCrewInfo() const;
};