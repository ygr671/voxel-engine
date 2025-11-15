#pragma once

#include <raylib.h>

class Voxel
{
private:
  static const Vector3 size_;
  Vector3 pos_;
  Color color_;
public:
  Voxel(Vector3 pos, Color color);
  static Vector3 const& get_size(); 
  BoundingBox get_bouding_box() const;
  void draw();
};
