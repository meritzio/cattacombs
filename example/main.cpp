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
    
    cout << "Graph topology: " << endl;
    gr->PrintTopology();
    
    //Place the graph into the geometry using connection rules
    cout << "Connecting graph" << endl;
    g.SetGraph(gr);
    
    //TODO Setup spatial connection rules to geometry
    /** CRITERIA
     *  1. Describe how far apart the entry point nodes need to be on the surface for acceptance
     *  2. Describe how far apart internal nodes need to be inside the volume for acceptance
     *  3. Run a RNG spacial placement according to these rules
     */
    
    //TODO Setup branches geometry between nodes
    /** CRITERIA
     *  1. Specify the how the branches between should look 
     *      (tunnel cross section profile (eg square/circlular),
     *      branch pathway curvature to avoid intersection, or just straight lines)
     *  2. Run with coefficients to drive path generation, geometry intersections/collisions not allowed
     *      could have ability to displace the placed nodes slightly until placement rules are satisfied
     */
    
    return 0;
}

