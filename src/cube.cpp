
#include "cube.hpp"

cattacombs::cube::cube(vector3 dimensions, vector3 position) :
    cattacombs::volume::volume(position)
{
    //Set the dimensions
    this->dimensions = dimensions;
    this->position   = position;
    
    //Make the eight points
    int nP = 8;
    float x2 = dimensions.x / 2,
          y2 = dimensions.y / 2,
          z2 = dimensions.z / 2;
    
    vertices = new vector3[nP] {
        vector3(-x2,-y2,-z2), //--- variations
        vector3( x2,-y2,-z2), //+--
        vector3( x2, y2,-z2), //++-
        vector3( x2, y2, z2), //+++
        vector3(-x2, y2, z2), //-++
        vector3(-x2,-y2, z2), //--+
        vector3( x2,-y2, z2), //+-+
        vector3(-x2, y2,-z2)  //-+-
    };
    
    //Make the twelve lines
    
    
    //Make the six surfaces
    
}

cattacombs::cube::~cube()
{
    delete[] vertices;
}

