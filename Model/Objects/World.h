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
    [[nodiscard]] int getParticleCount() const;
    void getParticlePosition(int index, float &x, float &y) const;
    [[nodiscard]] float getParticleRadius() const;
private:
    int width_;
    int height_;

    float particleRadius_;

    std::vector<Particle> particles_;
};



#endif //WORLD_H
