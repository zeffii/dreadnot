// font_parser.cpp
#include <regex>
#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <stdio.h>
#include "Font_Parser.h"


Font_Parser::Font_Parser(std::string filepath){
    load_font_file(filepath);
}

int Font_Parser::get_line_data(std::string input, std::string pattern) {
    int rval = 0;
    const std::regex r(pattern);
    std::smatch m;
    if (std::regex_search(input, m, r)) { rval = std::stoi(m[1].str()); }
    return rval;
};

void Font_Parser::load_font_file(std::string filepath){
    /*
    this does no clever introspection of the xml pointed at. it expects to
    find infoabout "count" (=n) on line 6 and then using that value it loops from
    the current line trough the next (n) lines, and regexes them to get the glyph elements

    this is not intended to be a generic font loader, but it was an interesting regex
    learning experience.
    */

    auto numregex = [](std::string item) { return item + R"(="(\d*)" ")"; };

    std::ifstream file (filepath);
    std::string s;

    // skip first few lines
    for (int i = 0; i <= 6; i++) getline(file, s);

    getline(file, s);
    int numchars = get_line_data(s, numregex("count"));
    std::vector<std::string> ascii_chars;
    for (int i=0; i < numchars; i++){
        getline(file, s);
        int gp[10] = {};
        for (int j=0; j < 10; j++) 
            gp[j] = get_line_data(s, numregex(elements[j]));

        Glyph glyph_char = {gp[0], gp[1], gp[2], gp[3], gp[4], gp[5], gp[6], gp[7], gp[8], gp[9]};
        glyph_remap[glyph_char.id] = i;
        glyphlist.push_back(glyph_char);
        char ch = (char) glyph_char.id;
        std::string str_repr_of_char(1, ch);
        ascii_chars.push_back(str_repr_of_char);
    }

    file.close();

    std::cout << "This is the list of available characters: \n";
    for (auto s: ascii_chars)
        std::cout << s << ", ";
    std::cout << std::endl;
};

Glyph Font_Parser::get_glyph_info(int character_index){
    return glyphlist[character_index];
};

void Font_Parser::print_glyph_info(std::string character){
    int ascii_int = int(character[0]);
    int glyph_index = glyph_remap[ascii_int];

    Glyph g = get_glyph_info(glyph_index);
    std::cout << "character: " << character << std::endl;
    std::cout << "glyph.id: " << g.id << std::endl;
    std::cout << "glyph.width: " << g.width << std::endl;
    std::cout << "glyph.x: " << g.x << std::endl;
    std::cout << "glyph.y: " << g.y << std::endl;
};


int Font_Parser::character_to_index(std::string ch){
    return 0;
};
