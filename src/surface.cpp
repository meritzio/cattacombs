
#include "surface.hpp"

cattacombs::surface::surface()
{

}

cattacombs::surface::surface(line* lineArray, int order[], const int count)
{
    for(int i = 0; i < count; i++) {
        wires.push_back(lineArray+order[i]);
    }
}

