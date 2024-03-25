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

    void accelerate(const Vector2f &acceleration);
    void applyConstraint();
    void update();
private:
    Vector2f position_current_;
    Vector2f position_old_;
    Vector2f acceleration_;
};



#endif //PARTICLE_H
