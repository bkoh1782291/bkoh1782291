#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
#include <string>

class Bird : public Animal {
    public:
        virtual std::string toString();
};

#endif
