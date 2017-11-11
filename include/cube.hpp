#ifndef CUBE_HPP
#define CUBE_HPP

#include "volume.hpp"

namespace cattacombs
{
    /**
     *  A helper cube for making an example catacomb, automakes the surfaces, lines and points required
     *  
     */
    class cube : public volume
    {
        public:
            cube(vector3 point, vector3 position);
            ~cube();
            
            ///The width, breadth and depth of the cube
            vector3 dimensions;
            
            ///The vertices of the cube
            vector3* vertices;
    };
}

#endif //CUBE_HPP
