
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
        vector3(-x2,-y2,-z2), //[0] --- variations
        vector3(-x2,-y2, z2), //[1] --+
        vector3(-x2, y2,-z2), //[2] -+-
        vector3(-x2, y2, z2), //[3] -++
        vector3( x2,-y2,-z2), //[4] +--
        vector3( x2,-y2, z2), //[5] +-+
        vector3( x2, y2,-z2), //[6] ++-
        vector3( x2, y2, z2)  //[7] +++
    };
    
    //Make the twelve lines
    int nL = 12;
    vector3* v = vertices; //abbreviation
    lines = new line[nL] {
        line(v[0], v[1]), //[00] 0-1 |Z
        line(v[2], v[3]), //[01] 2-3 
        line(v[4], v[5]), //[02] 4-5
        line(v[6], v[7]), //[03] 6-7
        line(v[0], v[2]), //[04] 0-2 |Y
        line(v[1], v[3]), //[05] 1-3
        line(v[4], v[6]), //[06] 4-6
        line(v[5], v[7]), //[07] 5-7
        line(v[0], v[4]), //[08] 0-4 |X
        line(v[1], v[5]), //[09] 1-5
        line(v[2], v[6]), //[10] 2-6
        line(v[3], v[7])  //[11] 3-7
    };
    
    //Make the six surfaces of four wires
    int nS = 6, nW = 4;
    line* l = lines; //abbreviation
    //Surface edge order
    int order[nS][nW] = {
        {0, 9, 2, 8},
        {1, 11, 3, 10},
        {0, 5, 1, 4},
        {2, 7, 3, 6},
        {4, 10, 6, 8},
        {5, 11, 6, 8}
    };
    
    surfaces = new surface[nS];
    for(int i = 0; i < nS; i++) {
        surfaces[i] = surface(l, order[i], nW);
    };
    
}

cattacombs::cube::~cube()
{
    
}

