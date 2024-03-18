//
// Created by tally on 16/03/24.
//

#include "Controller.h"
#include <unistd.h>

Controller::Controller() : model_(this), vue_(this) {}

void Controller::loop() {
    vue_.draw();
    sleep(5);
}

int Controller::getParticleCount() const {
    return model_.getParticleCount();
}

void Controller::getParticlePosition(const int i, float &x, float &y) const {
    model_.getParticlePosition(i, x, y);
}

float Controller::getParticleRadius() const {
    return model_.getParticleRadius();
}