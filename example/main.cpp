#include <iostream>
#include "cube.hpp"

using namespace std;
using namespace cattacombs;

int main(int argc, char** argv)
{
    cout << "Creating cube" << endl;
    
    cube* c = new cube(vector3(1.0f, 1.0f, 1.0f), vector3(0.0f, 0.0f, 0.0f));
    
    //Main section for building sample procedural cattacomb
    for(int i = 0; i < 8; i++)
        cout << c->vertices[i].x << ',' << c->vertices[i].y << ',' << c->vertices[i].z << endl;
    
    delete c;
    return 0;
}
