#pragma once

#include <raylib.h>

class Voxel
{
private:
  static constexpr Vector3 size_ = (Vector3){1.0f, 1.0f, 1.0f};
  Vector3 pos_;
  Color color_;

public:
  Voxel(Vector3 pos, Color color);
  void draw();
};
