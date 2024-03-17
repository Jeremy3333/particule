//
// Created by tally on 17/03/24.
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include "../Utils/Vector2f.h"

class Particle {
public:
    Particle(float x, float y);
    [[nodiscard]] Vector2f getPosition() const;
private:
    Vector2f position_;
};



#endif //PARTICLE_H
