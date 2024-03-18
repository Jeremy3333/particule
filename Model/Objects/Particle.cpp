//
// Created by tally on 17/03/24.
//

#include "Particle.h"

#include "../../Controller/Controller_const.h"

Particle::Particle(const float x,const float y): position_(x, y) {}

Vector2f Particle::getPosition() const {
    return position_;
}

void Particle::accelerate(const Vector2f &acceleration) {
    velocity_ += acceleration * (TIME_PER_FRAME / 1000.0f);
}

void Particle::update() {
    position_ += velocity_ * (TIME_PER_FRAME / 1000.0f);
}