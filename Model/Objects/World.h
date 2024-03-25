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
    [[nodiscard]] float getParticleRadius() const;
private:
    float width_;
    float height_;

    float particleRadius_;

    std::vector<Particle> particles_;

    void applyGravity();
    void applyConstraints();
    void updatePositions();
};



#endif //WORLD_H
