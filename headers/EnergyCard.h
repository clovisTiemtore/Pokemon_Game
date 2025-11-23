#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include <string>
#include <iostream>
#include "Card.h"

using namespace std;

class EnergyCard : public Card{
    
    private:
    string energyType;

    public:
    EnergyCard(const string& name, const string& type);
    void displayInfo() const override;
    string getEnergyType() const;

};

#endif
