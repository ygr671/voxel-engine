#include <cmath>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <vector>
#include <raylib.h>
#include <algorithm>
#include "includes/Map.hpp"

Map::Map(float length, float width, Color voxel_color): voxel_color_(voxel_color)
{
    if (length < 2.0f || width < 2.0f)
    {
        throw std::runtime_error("Error : map cannot have a height or width less than 2");
    }

    for (float x = 0 ; x < width ; x++)
    {
        for (float z = 0 ; z < length ; z++)
        {
            voxels_.push_back(
                Voxel(Vector3{x, 0.0f, z}, voxel_color_)
            );
        }
    }
}

void Map::draw()
{
    for (auto& voxel : voxels_)
    {
        voxel.draw();
    }
}

Voxel* Map::raycast(const Ray& ray)
{
    float best_distance = MAXFLOAT;
    Voxel* best_voxel = nullptr;
    // GetRayCollisionBox();
    for (Voxel& voxel : voxels_)
    {
        RayCollision col = GetRayCollisionBox(ray, voxel.get_bouding_box());
        if (col.hit && col.distance < best_distance)
        {
            best_distance = col.distance;
            best_voxel = &voxel;
        }
    }
    return best_voxel;
}

void Map::remove_voxel(Voxel* voxel)
{
    std::vector<Voxel>::iterator it;
    
    it = std::find_if(voxels_.begin(), voxels_.end(), [&voxel](Voxel& candidate){
        return voxel == &candidate;
    });

    if (it == voxels_.end())
    {
        return;
    }

    voxels_.erase(it);
}