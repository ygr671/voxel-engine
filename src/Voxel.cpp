#include "includes/Voxel.hpp"

#include <raylib.h>

Voxel::Voxel(Vector3 pos, Color color): pos_(pos), color_(color) {};

void Voxel::draw()
{
  DrawCubeV(pos_, size_, color_);
}

