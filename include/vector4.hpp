#ifndef VECTOR4_HPP
#define VECTOR4_HPP

namespace cattacombs
{
    /**
     *  Represents a quaternion
     *
     */
    class vector4
    {
        public:
            vector4();
            vector4(float x, float y, float z, float w);
            float x, y, z, w;
    };
}

#endif //VECTOR4_HPP
