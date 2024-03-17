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

    void drawBackground(int r, int g, int b, int a) const;
    void drawParticule(float x, float y, float radius, int r, int g, int b, int a) const;
    void Render() const;
private:
    SDL_Window* sdl_window_;
    SDL_Renderer* sdl_renderer_;

    void fillCircle(float x, float y, float r) const;
};



#endif //VUE_H
