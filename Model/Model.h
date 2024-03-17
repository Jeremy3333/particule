//
// Created by tally on 16/03/24.
//

#ifndef MODEL_H
#define MODEL_H

#include "Objects/World.h"

class Model {
public:
    [[nodiscard]] int getParticleCount() const;
    void getParticlePosition(int index, float &x, float &y) const;
    [[nodiscard]] int getParticleRadius() const;
private:
    World world_;
};



#endif //MODEL_H
