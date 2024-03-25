//
// Created by tally on 16/03/24.
//

#include "Controller.h"

Controller::Controller() : model_(this), vue_(this), running_(true) {}

void Controller::loop() {
    while (running_) {
        model_.update();
        vue_.input();
        vue_.draw();
        vue_.waitFrame();
    }
}

void Controller::stopRunning() {
    running_ = false;
}

int Controller::getParticleCount() const {
    return model_.getParticleCount();
}

void Controller::getParticlePosition(const int i, float &x, float &y) const {
    model_.getParticlePosition(i, x, y);
}

void Controller::getParticleRGB(int i, int &r, int &g, int &b, int &a) const {
    model_.getParticleRGB(i, r, g, b, a);
}


float Controller::getParticleRadius() const {
    return model_.getParticleRadius();
}