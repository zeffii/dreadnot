#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <string>

#include "Font_Parser.h"
#include "window.h"
#include "Glyph_Sheet.h"


void pollEvents(Window &window){
    SDL_Event event;

    if (SDL_PollEvent(&event)){
        window.pollEvents(event);
    }
}

int main(int argc, char* args[])
{
    Font_Parser font("res/consolas.fnt");
    Window window("bitmap font demo", 800, 600);
    Glyph_Sheet GS("res/consolas_0.png");

    while (!window.isClosed()){
        pollEvents(window);
        GS.display();
        window.clear();
    }
    return 0;
}