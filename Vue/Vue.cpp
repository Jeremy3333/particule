//
// Created by tally on 16/03/24.
//

#include <iostream>

#include "Vue.h"
#include "SDL_const.h"

Vue::Vue(){
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
