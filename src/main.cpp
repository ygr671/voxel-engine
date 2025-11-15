#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
#include <raylib.h>
#include <cmath>

#include "includes/Map.hpp"
#include "includes/GUI.hpp"

int main()
{
  constexpr int screen_width = 1920;
  constexpr int screen_height = 1080;
  constexpr int font_size = 20;

  InitWindow(screen_width, screen_height, "Voxel Engine - yzd");

  GUI gui(screen_width, screen_height, GetFontDefault(), font_size, "X");

  // First person camera
  Camera camera = {0};
  camera.position = (Vector3){0.0f, 2.0f, 4.0f};
  camera.target = (Vector3){0.0f, 2.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 60.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Map map(10, 10, GRAY);

  // For raycasting
  Vector3 voxel_size = Voxel::get_size();

  Ray ray = {0};
  RayCollision collision = {0};


  // Limite cursor to move only in the window
  DisableCursor();

  SetTargetFPS(60);


  while (!WindowShouldClose())
  {
    // Update
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
      // Raycasting
      ray = GetScreenToWorldRay(gui.get_cursor_position(), camera);
      Voxel* voxel = map.raycast(ray);
      if (voxel != nullptr)
      {
        map.remove_voxel(voxel);
      }
    }

    BeginDrawing(); 

      ClearBackground(SKYBLUE);

      BeginMode3D(camera);
        
        // Map (ground) drawing
        map.draw();

      EndMode3D();
      
      // GUI Drawing
      gui.draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
