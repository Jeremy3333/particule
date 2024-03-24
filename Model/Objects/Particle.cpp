//
// Created by tally on 17/03/24.
//

#include "Particle.h"

#include "../Model_const.h"

Particle::Particle(const float x,const float y): position_(x, y) {}

Vector2f Particle::getPosition() const {
    return position_;
}

void Particle::applyConstraint() {
    const Vector2f position(static_cast<float>(WORLD_WIDTH) / 2.0f, static_cast<float>(WORLD_HEIGHT) / 2.0f);
    const float radius = WORLD_HEIGHT / 2.0f;
    const Vector2f delta = position_ - position;
    const float distance = delta.length();
    if (distance > (radius - PARTICLE_RADIUS)) {
        // Calculate the corrected position to stay within the circular boundary
        Vector2f correctedPosition = position + delta * ((radius - PARTICLE_RADIUS) / distance);
        // Assign the corrected position to the particle's position
        position_ = correctedPosition;
    }
}

void Particle::accelerate(const Vector2f &acceleration) {
    velocity_ += acceleration * FIXED_TIME_STEP;
}

void Particle::update() {
    position_ += velocity_ * FIXED_TIME_STEP;
    applyConstraint();
}
