#pragma once

#include "Voxel.hpp"
#include <vector>
#include <raylib.h>

class Map
{
private:
    std::vector<Voxel> voxels_;
    Color voxel_color_;
public:
    Map(float length, float width, Color voxel_color);

    void draw();
    
    Voxel* raycast(const Ray& ray);
    void remove_voxel(Voxel* voxel);
};