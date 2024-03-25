//
// Created by tally on 17/03/24.
//

#include "World.h"

#include <iostream>

#include "../Model_const.h"

World::World(): width_(WORLD_WIDTH), height_(WORLD_HEIGHT), particleRadius_(PARTICLE_RADIUS), particle_time(0.0f) {
    float y = height_/2.0f;
    float x = (width_/2.0f) - 150.0f;
    particles_.emplace_back(x, y);
}

void World::update() {

    if(particle_time > 0.1f){
        particle_time = 0.0f;
        newParticle(width_/2.0f - 150.0f, height_/2.0f);
    }
    else {
        particle_time += FIXED_TIME_STEP;
    }

    applyGravity();
    applyConstraints();
    solveCollisions();
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

void World::newParticle(const float x, const float y) {
    particles_.emplace_back(x, y);
}

void World::applyGravity() {
    for (auto &particle : particles_) {
        particle.accelerate(Vector2f(0.0f, 100.0f));
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
void World::solveCollisions() {
    for (size_t i = 0; i < particles_.size(); ++i) {
        for (size_t j = i + 1; j < particles_.size(); ++j) {
            auto& particle1 = particles_[i];
            auto& particle2 = particles_[j];

            const Vector2f collisionVector = particle1.getPosition() - particle2.getPosition();
            const float distance = collisionVector.length();

            if (distance < 2.0f * particleRadius_) {
                const Vector2f normal = collisionVector / distance;
                const float delta = 2.0f * particleRadius_ - distance;

                particle1.setPosition(particle1.getPosition() + normal * delta / 2.0f);
                particle2.setPosition(particle2.getPosition() - normal * delta / 2.0f);
            }
        }
    }
}
