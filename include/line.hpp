#ifndef LINE_HPP
#define LINE_HPP

#include "vector3.hpp"

namespace cattacombs
{
    /**
     *  Represents a linear line of two bound points
     *  
     */ 
    class line
    {
        public:
            line(vector3 start=vector3(), vector3 end=vector3());
            ~line();
            vector3* points;
    };
}

#endif //LINE_HPP
