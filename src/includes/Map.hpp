#pragma once

#include "Voxel.hpp"
#include <vector>
#include <raylib.h>

struct RaycastData
{
    Voxel* voxel;
    RayCollision collision;
};

class Map
{
private:
    std::vector<Voxel> voxels_;
    Color voxel_color_;
public:
    Map(float length, float width, Color voxel_color);

    void draw();
    
    RaycastData raycast(const Ray& ray);
    void add_voxel(Vector3 pos);
    void remove_voxel(Voxel* voxel);
};