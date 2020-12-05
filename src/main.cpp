#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <string>

#include "Font_Parser.h"
#include "window.h"


void pollEvents(Window &window){
    SDL_Event event;

    if (SDL_PollEvent(&event)){
        window.pollEvents(event);
    }
}

int main(int argc, char* args[])
{

    Font_Parser font("res/consolas.fnt");
    Window window( "SDL Tutorial", 800, 600);

    while (!window.isClosed()){
        pollEvents(window);
        window.clear();
    }
    return 0;
}