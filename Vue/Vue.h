//
// Created by tally on 16/03/24.
//

#ifndef VUE_H
#define VUE_H

#include <SDL2/SDL.h>

class Controller;

class Vue {
public:
    explicit Vue(Controller *controller);
    ~Vue();

    void input() const;
    void draw() const;
    void waitFrame();
private:
    SDL_Window* sdl_window_;
    SDL_Renderer* sdl_renderer_;
    int lastFrameTime_;
    float fps;
    Controller* controller_;

    void drawBackground(int r, int g, int b, int a) const;
    void drawParticule(float x, float y, float radius, int r, int g, int b, int a) const;
    void Render() const;

    void fillCircle(float x, float y, float r) const;
};



#endif //VUE_H
