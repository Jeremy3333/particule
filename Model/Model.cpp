//
// Created by tally on 16/03/24.
//

#include "Model.h"
#include "../Controller/Controller.h"

Model::Model(Controller *controller) : controller_(controller) {}

void Model::update() {
    world_.update();
}


int Model::getParticleCount() const {
    return world_.getParticleCount();
}

void Model::getParticlePosition(const int index, float &x, float &y) const {
    world_.getParticlePosition(index, x, y);
}

void Model::getParticleRGB(int index, int &r, int &g, int &b, int &a) const {
    world_.getParticleRGB(index, r, g, b, a);
}


float Model::getParticleRadius() const {
    return world_.getParticleRadius();
}