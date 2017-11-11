#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <vector>
#include "line.hpp"

using namespace std;

namespace cattacombs
{
    /**
     *  A 3D geometric planar surface bound by wires
     *
     */ 
    class surface
    {
        public:
            ///default constructor
            surface();
            ///Pass an array of lines and an index map for making the wire array
            surface(line* lineArray, int order[], const int count);
            
            ///The wire references
            vector<line*> wires;
    };
}

#endif //SURFACE_HPP
