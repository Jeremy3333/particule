//
// Created by tally on 16/03/24.
//

#ifndef VUE_H
#define VUE_H

#include <SDL2/SDL.h>

class Vue {
public:
    Vue();
    ~Vue();
private:
    SDL_Window* sdl_window_;
    SDL_Renderer* sdl_renderer_;
};



#endif //VUE_H
