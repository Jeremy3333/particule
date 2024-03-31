//
// Created by tally on 17/03/24.
//

#include "World.h"

#include <iostream>
#include <random>

#include "../Model_const.h"

World::World(): width_(WORLD_WIDTH), height_(WORLD_HEIGHT), particleRadius_(PARTICLE_RADIUS), particle_time(0.0f) {
}
void HsvToRgb(float h, float s, float v, int& r, int& g, int& b) {
    int i;
    float f, p, q, t;

    if (s == 0) {
        r = g = b = static_cast<int>(v * 255.0f);
        return;
    }

    h /= 60;                        // sector 0 to 5
    i = static_cast<int>(std::floor(h));
    f = h - i;                      // factorial part of h
    p = v * (1 - s);
    q = v * (1 - s * f);
    t = v * (1 - s * (1 - f));

    switch (i) {
        case 0:
            r = static_cast<int>(v * 255.0f);
        g = static_cast<int>(t * 255.0f);
        b = static_cast<int>(p * 255.0f);
        break;
        case 1:
            r = static_cast<int>(q * 255.0f);
        g = static_cast<int>(v * 255.0f);
        b = static_cast<int>(p * 255.0f);
        break;
        case 2:
            r = static_cast<int>(p * 255.0f);
        g = static_cast<int>(v * 255.0f);
        b = static_cast<int>(t * 255.0f);
        break;
        case 3:
            r = static_cast<int>(p * 255.0f);
        g = static_cast<int>(q * 255.0f);
        b = static_cast<int>(v * 255.0f);
        break;
        case 4:
            r = static_cast<int>(t * 255.0f);
        g = static_cast<int>(p * 255.0f);
        b = static_cast<int>(v * 255.0f);
        break;
        default:        // case 5:
            r = static_cast<int>(v * 255.0f);
        g = static_cast<int>(p * 255.0f);
        b = static_cast<int>(q * 255.0f);
        break;
    }
}

void rainbow(float maxParticles, float size, int &r, int &g, int &b) {
    float ratio = size / maxParticles;
    float hue = ratio * 360.0f;  // Map ratio to hue angle (0-360)

    HsvToRgb(hue, 1.0f, 1.0f, r, g, b);
}

void World::update() {
    const uint32_t sub_steps = 8;
    const float dt = FIXED_TIME_STEP / static_cast<float>(sub_steps);
    constexpr float maxParticles = 500;
    for(uint32_t i(sub_steps); i--;){
    if(particle_time > 0.5 && static_cast<float>(particles_.size()) < maxParticles){
        particle_time = 0.0f;
        float y = height_/2.0f;
        float x = (width_/2.0f);
        int r, g, b;
        rainbow(maxParticles, static_cast<float>(particles_.size()), r, g, b);

        particles_.emplace_back(x, y, r, g, b, 255);
    }
    else {
        particle_time += dt;
    }

    applyGravity();
    applyConstraints();
    solveCollisions();
    updatePositions(dt);
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

void World::getParticleRGB(int index, int &r, int &g, int &b, int &a) const {
    particles_[index].getRGB(r, g, b, a);
}


float World::getParticleRadius() const {
    return particleRadius_;
}

void World::newParticle(float x, float y, int r, int g, int b, int a) {
    particles_.emplace_back(x, y, r, g, b, a);
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

void World::updatePositions(float dt) {
    for (auto &particle : particles_) {
        particle.update(dt);
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
