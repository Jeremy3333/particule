//
// Created by tally on 16/03/24.
//

#include "Controller.h"
#include "Controller_const.h"

void Controller::draw() const{
    vue_.drawBackground(0, 0, 0, 255);
    const int nbParticules = model_.getParticleCount();
    for (int i = 0; i < nbParticules; i++) {
        float x, y;
        model_.getParticlePosition(i, x, y);
        const float radius = model_.getParticleRadius() * ZOOM_FACTOR;
        vue_.drawParticule(x, y, radius, 255, 255, 255, 255);
    }
    vue_.Render();
}