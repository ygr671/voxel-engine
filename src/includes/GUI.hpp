#pragma once

#include <raylib.h>
#include <cstdint>
#include <string>
// Specifity : this class SHOULD be a singleton.

class GUI
{
private:
    std::size_t width_;
    std::size_t height_;
    Font font_;
    std::size_t font_size_;
    std::string cursor_;
public:
    GUI(std::size_t width, std::size_t height, Font font, std::size_t font_size, std::string cursor);
    void draw();
    Vector2 get_cursor_position();
};