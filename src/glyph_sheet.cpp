#include "window.h"
#include "Glyph_Sheet.h"
#include <string>
#include <iostream>


Glyph_Sheet::Glyph_Sheet(const std::string filepath){
    SDL_Surface *surface = IMG_Load(filepath.c_str());
    if (!surface){ std::cerr << "Failed to create surface \n"; }
    _w = surface->w;
    _h = surface->h;

    glyph_sheet_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
    if (!glyph_sheet_texture){ std::cerr << "failed to create texture\n"; }

    SDL_FreeSurface(surface);

};

Glyph_Sheet::~Glyph_Sheet(){
    SDL_DestroyTexture(glyph_sheet_texture);
};

void Glyph_Sheet::display() const {
    SDL_Rect rect = {_x, _y, _w, _h};
    if (glyph_sheet_texture)
        SDL_RenderCopy(Window::renderer, glyph_sheet_texture, nullptr, &rect);
};

void Glyph_Sheet::update_location(int x, int y){

};

void Glyph_Sheet::clear(){

};