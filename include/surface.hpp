#ifndef SURFACE_HPP
#define SURFACE_HPP

#include "line.hpp"

namespace cattacombs
{
    /**
     *  A 3D geometric planar surface bound by wires
     *
     */ 
    class surface
    {
        public:
            surface();
            line* wires;
    };
}

#endif //SURFACE_HPP
