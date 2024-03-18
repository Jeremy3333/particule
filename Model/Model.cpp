//
// Created by tally on 16/03/24.
//

#include "Model.h"
#include "../Controller/Controller.h"

Model::Model(Controller *controller) : controller_(controller) {}

int Model::getParticleCount() const {
    return world_.getParticleCount();
}

void Model::getParticlePosition(const int index, float &x, float &y) const {
    world_.getParticlePosition(index, x, y);
}

float Model::getParticleRadius() const {
    return world_.getParticleRadius();
}