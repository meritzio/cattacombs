#ifndef VOLUME_HPP
#define VOLUME_HPP

#include "surface.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

namespace cattacombs
{
    /**
     *  Represents a bound set of surfaces forming a volume
     *
     */
    class volume
    {
        public:
            volume();
            volume(vector3 position, vector4 rotation=vector4(0.0f, 0.0f, 0.0f, 0.0f), vector3 scale=vector3(1.0f, 1.0f, 1.0f));
            ~volume();
            
            vector3 GetRandomSurfacePoint();
            
            surface* surfaces;
            line* lines;
            vector3* vertices;
            
            ///The position in world space
            vector3 position;
            ///The quaternion rotation in world space
            vector4 rotation;
            ///The scale in world space
            vector3    scale;

    };
}

#endif //VOLUME_HPP
