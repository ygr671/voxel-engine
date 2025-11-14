#include <iostream>
#include <string>
#include <raylib.h>

int main()
{
  const int screen_width = 800;
  const int screen_height = 480;
  const int font_size = 20;

  InitWindow(screen_width, screen_height, "Voxel Engine - yzd");

  // First person camera
  Camera camera = {0};
  camera.position = (Vector3){0.0f, 2.0f, 4.0f};
  camera.target = (Vector3){0.0f, 2.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 60.0f;
  camera.projection = CAMERA_PERSPECTIVE;
  
  // Limite cursor to move only in the window
  DisableCursor();


  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    // Update
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
    
    /*
    if (IsKeyDown(KEY_RIGHT)) {}
    */

    BeginDrawing(); 
      ClearBackground(RAYWHITE);

      BeginMode3D(camera);
        DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f}, (Vector2){ 32.0f, 32.0f}, LIGHTGRAY);
        DrawCubeV((Vector3){2.0f, 1.0f, 0.0f}, (Vector3){1.0f, 1.0f, 1.0f}, RED);
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
