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
    void stopRunning();

    [[nodiscard]] int getParticleCount() const;
    void getParticlePosition(int i, float &x, float &y) const;
    void getParticleRGB(int i, int &r, int &g, int &b, int &a) const;
    [[nodiscard]] float getParticleRadius() const;
private:
    Model model_;
    Vue vue_;

    bool running_;
};



#endif //CONTROLLER_H
