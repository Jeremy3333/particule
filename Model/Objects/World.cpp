//
// Created by tally on 17/03/24.
//

#include "World.h"

#include <iostream>

#include "../Model_const.h"

World::World(): width_(WORLD_WIDTH), height_(WORLD_HEIGHT), particleRadius_(PARTICLE_RADIUS) {
    float y = height_/2.0f;
    float x = (width_/2.0f)+y;
    particles_.emplace_back(x, y);
}

void World::update() {
    applyGravity();
    applyConstraints();
    updatePositions();
}

int World::getParticleCount() const {
    return static_cast<int>(particles_.size());
}

void World::getParticlePosition(const int index, float &x, float &y) const {
    const Vector2f position = particles_[index].getPosition();
    x = position.x;
    y = position.y;
}

float World::getParticleRadius() const {
    return particleRadius_;
}

void World::applyGravity() {
    for (auto &particle : particles_) {
        particle.accelerate(Vector2f(0.0f, 1000.0f));
    }
}

void World::applyConstraints() {
    for (auto &particle : particles_) {
        particle.applyConstraint();
    }
}

void World::updatePositions() {
    for (auto &particle : particles_) {
        particle.update();
    }
}
