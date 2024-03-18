//
// Created by tally on 17/03/24.
//

#include "World.h"
#include "../Model_const.h"

World::World(): width_(WORLD_WIDTH), height_(WORLD_HEIGHT), particleRadius_(PARTICLE_RADIUS) {
 particles_.emplace_back(width_/2, height_/2);
}

void World::update() {
    for (auto &particle : particles_) {
        particle.accelerate(Vector2f(0, 9.81));
        particle.update();
    }
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
