#ifndef VECTOR3_HPP
#define VECTOR3_HPP

namespace cattacombs
{
    /**
     *  Represents spatial points or vectors
     *
     */
    class vector3
    {
        public:
            ///Construct a vector at origin
            vector3();
            vector3(float x, float y, float z);
            float x, y, z;
    };
}

#endif //VECTOR3_HPP
