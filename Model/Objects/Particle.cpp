//
// Created by tally on 17/03/24.
//

#include "Particle.h"

#include "../Model_const.h"

 Particle::Particle(float x, float y, int r, int g, int b, int a) : position_current_(x, y), position_old_(x, y), acceleration_(0, 0), r_(r), g_(g), b_(b), a_(a) {}


Vector2f Particle::getPosition() const {
    return position_current_;
}

void Particle::setPosition(const Vector2f &position) {
    position_current_ = position;
}

void Particle::getRGB(int &r, int &g, int &b, int &a) const {
    r = r_;
    g = g_;
    b = b_;
    a = a_;
 }


void Particle::applyConstraint() {
    const Vector2f position(static_cast<float>(WORLD_WIDTH) / 2.0f, static_cast<float>(WORLD_HEIGHT) / 2.0f);
    const float radius = WORLD_HEIGHT / 2.0f;
    const Vector2f delta = position_current_ - position;
    const float distance = delta.length();
    if (distance > (radius - PARTICLE_RADIUS)) {
        // Calculate the corrected position to stay within the circular boundary
        Vector2f correctedPosition = position + delta * ((radius - PARTICLE_RADIUS) / distance);
        // Assign the corrected position to the particle's position
        position_current_ = correctedPosition;
    }
}

void Particle::update() {
    Vector2f velocity = position_current_ - position_old_;
    position_old_ = position_current_;
    position_current_ = position_current_ + velocity + acceleration_ * FIXED_TIME_STEP * FIXED_TIME_STEP;
    acceleration_ = Vector2f(0, 0);
}

void Particle::accelerate(const Vector2f &acc) {
    acceleration_ += acc;
}