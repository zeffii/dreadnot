// Font_Parser.h
#include <string>
#include <Glyph.h>
#include <map>

class Font_Parser {

    public:
        Font_Parser(std::string filepath);
        Glyph get_glyph_info(int character);
        int get_line_data(std::string input, std::string pattern);
        void load_font_file(std::string filepath);
        void print_glyph_info(std::string character);
        int character_to_index(std::string ch);

    private:
        std::vector<std::string> elements = {
            "id", "x", "y", "width", "height",
            "xoffset", "yoffset", "xadvance", "page", "chnl"
        };
        std::vector<Glyph> glyphlist;
        std::map<int, int> glyph_remap;

};