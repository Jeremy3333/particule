//
// Created by tally on 16/03/24.
//

#include "Model.h"

int Model::getParticleCount() const {
    return world_.getParticleCount();
}

void Model::getParticlePosition(const int index, float &x, float &y) const {
    world_.getParticlePosition(index, x, y);
}

int Model::getParticleRadius() const {
    return world_.getParticleRadius();
}