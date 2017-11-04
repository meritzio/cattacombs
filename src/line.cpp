#include "line.hpp"

cattacombs::line::line(vector3 v0, vector3 v1)
{
    this->points = new vector3[2] { v0, v1 };
}

cattacombs::line::~line()
{
    delete[] this->points;
}

