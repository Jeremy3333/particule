//
// Created by tally on 17/03/24.
//

#include "Particle.h"

Particle::Particle(const float x,const float y): position_(x, y) {}

Vector2f Particle::getPosition() const {
    return position_;
}