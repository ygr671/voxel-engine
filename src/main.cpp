#include <iostream>
#include <string>
#include <vector>
#include <raylib.h>
#include <cmath>
#include "includes/Voxel.hpp"

int main()
{
  constexpr int screen_width = 1920;
  constexpr int screen_height = 1080;
  constexpr int font_size = 20;

  InitWindow(screen_width, screen_height, "Voxel Engine - yzd");

  // First person camera
  Camera camera = {0};
  camera.position = (Vector3){0.0f, 2.0f, 4.0f};
  camera.target = (Vector3){0.0f, 2.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 60.0f;
  camera.projection = CAMERA_PERSPECTIVE;
  
  std::vector<Voxel> map{};
  
  float y_height = 1.0f;
  for (size_t y = 0 ; y < 3 ; y++)
  {
    for (size_t x = 0 ; x < 3 ; x++)
    {
      map.push_back(Voxel((Vector3){2.0f + x, 1.0f + y, 0.0f}, RED));
    }
  }

  // Limite cursor to move only in the window
  DisableCursor();

  SetTargetFPS(60);


  while (!WindowShouldClose())
  {
    // Update
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
    
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    {
      float pos_y = (static_cast<float>(floor(camera.target.y)) < 0.5f) ? 0.5f : static_cast<float>(floor(camera.target.y));
      Vector3 voxel_pos = (Vector3){
        static_cast<float>(floor(camera.target.x)), 
        pos_y, 
        static_cast<float>(floor(camera.target.z))
      };
      map.push_back(Voxel(voxel_pos, RED));
    }

    /*
    if (IsKeyDown(KEY_UP)) * 0.1f; 
    if (IsKeyDown(KEY_DOWN)) * 0.1f;
    if (IsKeyDown(KEY_LEFT)) * 0.1f
    if (IsKeyDown(KEY_RIGHT)) 
    */

    BeginDrawing(); 
      ClearBackground(RAYWHITE);

      BeginMode3D(camera);
        DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f}, (Vector2){ 32.0f, 32.0f}, LIGHTGRAY);
        
        for (Voxel voxel : map)
        {
          voxel.draw();
        }

      EndMode3D();
      
      // Drawing FPS top-left corner
      std::string fps = std::to_string(GetFPS());
      const int fps_width = MeasureText(fps.c_str(), font_size);
      DrawText(fps.c_str(), 2, 0, font_size, BLACK);


      std::string cursor = "X";
      const int cursor_width = MeasureText(cursor.c_str(), font_size);
      DrawText(cursor.c_str(), (screen_width - cursor_width) / 2, (screen_height - font_size) / 2, font_size, BLACK);
     
      
      
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
