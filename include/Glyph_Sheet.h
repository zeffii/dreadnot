#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Glyph_Sheet {

    public:
        Glyph_Sheet(const std::string filepath);
        ~Glyph_Sheet();
        void display() const;
        void update_location(int x, int y);
        void clear();
    private:
        int _w, _h;
        int _x = 20;
        int _y = 20;
        SDL_Texture *glyph_sheet_texture = nullptr;  


};