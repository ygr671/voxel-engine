#include <raylib.h>
#include "includes/GUI.hpp"
#include <string>

GUI::GUI(std::size_t width, std::size_t height, Font font, std::size_t font_size, std::string cursor): width_(width), height_(height), font_(font), font_size_(font_size), cursor_(cursor) {}

void GUI::draw()
{
    // Drawing FPS top-left corner
    std::string fps = std::to_string(GetFPS());
    const int fps_width = MeasureText(fps.c_str(), font_size_);
    DrawText(fps.c_str(), 2, 0, font_size_, BLACK);

    Vector2 cursor_pos = get_cursor_position();
    DrawText(cursor_.c_str(), cursor_pos.x, cursor_pos.y, font_size_, BLACK);   
}

Vector2 GUI::get_cursor_position()
{
    const int cursor_width = MeasureText(cursor_.c_str(), font_size_);
    return Vector2{(static_cast<float>(width_) - cursor_width) / 2, (static_cast<float>(height_) - font_size_) / 2};
}