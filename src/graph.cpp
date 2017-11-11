#include "graph.hpp"
#include <vector>

using namespace std;

cattacombs::graph::graph()
{
    
}

cattacombs::graph::~graph()
{
    int nNodes = nodes.size();

    for(int i = 0; i < nNodes; i++) {
        delete nodes[i];
    }
    
    nodes.clear();
}

void cattacombs::graph::AddNode(node* n)
{
    nodes.push_back(n);
}

cattacombs::graph* cattacombs::graph::FromRandom(const int nInnerNodes, const int nOuterNodes)
{
    int nodecount = nInnerNodes + nOuterNodes;
    graph* g = new graph();
    
    vector<node*> internals;
    vector<node*> externals;
    
    //Dynamically allocate the nodes
    for(int i =0; i < nOuterNodes; i++) {
        node* n = new node();
        externals.push_back(n);
        g->AddNode(n);
    }
    
    for(int i = 0; i < nInnerNodes; i++) {
        node* n = new node();
        internals.push_back(n);
        g->AddNode(n);
    }
    
    //Now make random procedural connections
    //TODO make connections, with reasonable looping restraints
    
    return g;
}


