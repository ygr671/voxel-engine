#include "includes/Voxel.hpp"

#include <raylib.h>

const Vector3 Voxel::size_ = {1.0f, 1.0f, 1.0f};

Voxel::Voxel(Vector3 pos, Color color): pos_(pos), color_(color) {};

void Voxel::draw()
{
  DrawCubeV(pos_, size_, color_);
  DrawCubeWires(pos_, size_.x, size_.y, size_.z, BLACK);
}

Vector3 const& Voxel::get_size()
{
  return Voxel::size_;
}

BoundingBox Voxel::get_bouding_box() const
{
  return {
    {pos_.x - size_.x / 2, pos_.y - size_.y / 2, pos_.z - size_.z / 2},
    {pos_.x + size_.x / 2, pos_.y + size_.y / 2, pos_.z + size_.z / 2}
  };
}
