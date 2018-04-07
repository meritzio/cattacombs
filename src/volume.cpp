#include "volume.hpp"

cattacombs::volume::volume()
{
    this->surfaces = nullptr;
    this->position = vector3(0.0f, 0.0f, 0.0f);
    this->rotation = vector4(0.0f, 0.0f, 0.0f, 0.0f);
    this->scale    = vector3(1.0f, 1.0f, 1.0f);
    this->lines = nullptr;
    this->vertices = nullptr;
}

cattacombs::volume::volume(vector3 position, vector4 rotation, vector3 scale)
{
    this->surfaces = nullptr;
    this->position = position;
    this->rotation = rotation;
    this->scale    = scale;
    this->lines = nullptr;
    this->vertices = nullptr;
}

cattacombs::volume::~volume()
{
    delete[] surfaces;
    delete[] lines;
    delete[] vertices;
}

cattacombs::vector3 cattacombs::volume::GetRandomSurfacePoint()
{
    //TODO implementation of selecting a random point on surface using RNG
    return vector3();
}
