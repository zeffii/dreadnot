//window.cpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "Window.h"
using namespace std;

SDL_Renderer *Window::renderer = nullptr;

Window::Window(const string &title, int width, int height)
:_title(title), _width(width), _height(height){
    _closed = !init();   
}

Window::~Window(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    SDL_Quit();
}

bool Window::init(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        cerr << "Failed to init SDL.\n"; return false;
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG){
        cerr << "Failed to init SDL img\n"; return false;
    }

    _window = SDL_CreateWindow(
        _title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        _width, _height,
        0  // SDL_WINDOW_RESIZABLE
    );

    if (_window == nullptr) {
        cerr << "Failed to create window! :/ \n"; return false;
    }

    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) {
        cerr << "Failed to create renderer!\n"; return false;
    }

    return true;
}

void Window::pollEvents(SDL_Event &event){
    switch (event.type){
        case SDL_QUIT:
            _closed = true;
            break;
        case SDL_KEYDOWN:
                
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    _closed = true;
                    break;
                default:
                    break;                    
            }
            break;

         default:
            break;
    }
}

void Window::clear() const {
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 125, 125, 125, 255);
    SDL_RenderClear(renderer);

}