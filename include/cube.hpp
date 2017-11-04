#ifndef CUBE_HPP
#define CUBE_HPP

#include "volume.hpp"

namespace cattacombs
{
    /**
     *  A helper cube for making an example catacomb, automakes the surfaces, lines and points required
     *  
     */
    class cube : volume
    {
        public:
            cube(vector3 point, vector3 position);
            
            ///The width, breadth and depth of the cube
            vector3 dimensions;
    };
}

#endif //CUBE_HPP
