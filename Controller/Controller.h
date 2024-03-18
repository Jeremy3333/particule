//
// Created by tally on 16/03/24.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/Model.h"
#include "../Vue/Vue.h"


class Controller {
public:
    Controller();

    void loop();

    [[nodiscard]] int getParticleCount() const;
    void getParticlePosition(int i, float &x, float &y) const;
    [[nodiscard]] float getParticleRadius() const;
private:
    Model model_;
    Vue vue_;
};



#endif //CONTROLLER_H
