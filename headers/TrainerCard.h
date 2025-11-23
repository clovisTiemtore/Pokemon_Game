#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"
#include <string>
using namespace std;

class TrainerCard : public Card {
private:
    string effect;

public:
    TrainerCard(const string& name, const string& effect);
    void displayInfo() const override;
    string getEffect() const;
};

#endif
