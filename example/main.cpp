#include <iostream>
#include "generator.hpp"
#include "cube.hpp"

using namespace std;
using namespace cattacombs;

int main(int argc, char** argv)
{
    cout << "Creating generator" << endl;
    generator g = generator();
    
    cout << "Creating cube for external geometry" << endl;
    cube c = cube(vector3(1.0f, 1.0f, 1.0f), vector3(0.0f, 0.0f, 0.0f));
    
    //Main section for building sample procedural cattacomb
    cout << "Setting external geometry reference" << endl;
    g.SetExternalGeometry(&c);
    
    //Create a random graph for placement logic
    cout << "Randomly generating graph" << endl;
    graph* gr = graph::FromRandom(5, 7);
    
    //Place the graph into the geometry using connection rules
    cout << "Connecting graph" << endl;
    g.SetGraph(gr);
    
    //TODO Apply connection rules
    
    for(int i = 0; i < 8; i++)
        cout << c.vertices[i].x << ',' << c.vertices[i].y << ',' << c.vertices[i].z << endl;
    
    return 0;
}

