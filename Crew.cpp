#include "Crew.h"

Crew::Crew(std::string n, std::string pos, int exp)
    : name(n), position(pos), experience(exp)
{
}

std::string Crew::getName() const
{
    return name;
}

std::string Crew::getPosition() const
{
    return position;
}

int Crew::getExperience() const
{
    return experience;
}

void Crew::displayCrewInfo() const
{
    std::cout << "Crew Member - Name: " << name 
              << ", Position: " << position 
              << ", Experience: " << experience << " years" << std::endl;
}