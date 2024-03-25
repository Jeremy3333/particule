//
// Created by tally on 16/03/24.
//

#include <iostream>

#include "Vue.h"
#include "SDL_const.h"
#include "../Controller/Controller.h"

Vue::Vue(Controller *controller) : controller_(controller), lastFrameTime_(0) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(SDL_EXIT_ERROR);
    }

    sdl_window_ = SDL_CreateWindow(SDL_WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_WINDOW_WIDTH, SDL_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (sdl_window_ == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(SDL_EXIT_ERROR);
    }

    sdl_renderer_ = SDL_CreateRenderer(sdl_window_, SDL_RENDERER_INDEX, SDL_RENDERER_ACCELERATED);
    if (sdl_renderer_ == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(SDL_EXIT_ERROR);
    }
}

Vue::~Vue() {
    SDL_DestroyRenderer(sdl_renderer_);
    SDL_DestroyWindow(sdl_window_);
    SDL_Quit();
}

void Vue::input() const {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            controller_->stopRunning();
        }
    }
}


void Vue::draw() const{
    // display title + fps
    SDL_SetWindowTitle(sdl_window_, (SDL_WINDOW_TITLE " - " + std::to_string(fps) + " fps").c_str());
    drawBackground(0, 0, 0, 255);
    const int nbParticules = controller_->getParticleCount();
    for (int i = 0; i < nbParticules; i++) {
        float x, y;
        controller_->getParticlePosition(i, x, y);
        const float radius = controller_->getParticleRadius() * ZOOM_FACTOR;
        drawParticule(x, y, radius, 255, 255, 255, 255);
    }
    Render();
}

void Vue::waitFrame() {
    const int currentTime = static_cast<int>(SDL_GetTicks());
    if (const int timeToWait = SDL_FRAME_TIME - (currentTime - lastFrameTime_); timeToWait > 0) {
        SDL_Delay(static_cast<Uint32>(timeToWait));
    }
    fps = 1000.0f / (static_cast<int>(SDL_GetTicks()) - lastFrameTime_);
    lastFrameTime_ = currentTime;
}

void Vue::drawBackground(const int r, const int g, const int b, const int a) const {
    SDL_SetRenderDrawColor(sdl_renderer_, r, g, b, a);
    SDL_RenderClear(sdl_renderer_);
}

void Vue::drawParticule(const float x, const float y, const float radius, const int r, const int g, const int b, const int a) const{
    SDL_SetRenderDrawColor(sdl_renderer_, r, g, b, a);
    fillCircle(x, y, radius);
}

void Vue::Render() const{
    SDL_RenderPresent(sdl_renderer_);
}

void Vue::fillCircle(const float x, const float y, const float r) const {
    //std::cout << "x: " << x << " y: " << y << std::endl;
    int cx = static_cast<int>(r);
    int cy = 0;
    int radiusError = 1 - cx;

    while (cx >= cy) {
        for (int i = static_cast<int>(x) - cx; i <= static_cast<int>(x) + cx; i++) {
            SDL_RenderDrawPoint(sdl_renderer_, i, static_cast<int>(y) + cy);
            SDL_RenderDrawPoint(sdl_renderer_, i, static_cast<int>(y) - cy);
        }
        for (int i = static_cast<int>(x) - cy; i <= static_cast<int>(x) + cy; i++) {
            SDL_RenderDrawPoint(sdl_renderer_, i, static_cast<int>(y) + cx);
            SDL_RenderDrawPoint(sdl_renderer_, i, static_cast<int>(y) - cx);
        }

        cy++;

        if (radiusError < 0) {
            radiusError += 2 * cy + 1;
        } else {
            cx--;
            radiusError += 2 * (cy - cx + 1);
        }
    }
}
