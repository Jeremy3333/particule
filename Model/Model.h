//
// Created by tally on 16/03/24.
//

#ifndef MODEL_H
#define MODEL_H

#include "Objects/World.h"

class Controller;

class Model {
public:
    explicit Model(Controller *controller);
    [[nodiscard]] int getParticleCount() const;
    void getParticlePosition(int index, float &x, float &y) const;
    [[nodiscard]] float getParticleRadius() const;
private:
    Controller* controller_;
    World world_;
};



#endif //MODEL_H
