//
// Created by tally on 17/03/24.
//

#ifndef WORLD_H
#define WORLD_H

#include "Particle.h"

#include <vector>

class World {
public:
    World();

    void update();

    [[nodiscard]] int getParticleCount() const;
    void getParticlePosition(int index, float &x, float &y) const;
    void getParticleRGB(int index, int &r, int &g, int &b, int &a) const;
    [[nodiscard]] float getParticleRadius() const;
private:
    float width_;
    float height_;

    float particleRadius_;
    float particle_time;


    std::vector<Particle> particles_;

    void newParticle(float x, float y, int r, int g, int b, int a);

    void applyGravity();
    void applyConstraints();
    void updatePositions(float dt);

    void solveCollisions();
};



#endif //WORLD_H
