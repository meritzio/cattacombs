#ifndef GRAPH_H
#define GRAPH_H

#include "node.hpp"
#include <vector>

using namespace std;

namespace cattacombs
{
    /**
     *  The graph that holds all nodal connections
     *  
     */
    class graph
    {
        public:
            ///Construct a graph
            graph();
            ///Deallocate the graph and its child nodes
            ~graph();
            
            //Add a dynamically allocated node to the graph
            void AddNode(node* n);
            
            ///Create a dynamically allocated graph from random, given a number of nodes to formulate the connections 
            /// (connections within reason)
            static graph* FromRandom(const int nInnerNodes, const int nOuterNodes);
            
        private:
            ///The list of nodes that make up the graph
            vector<node*> nodes;
    };
}

#endif //GRAPH_H
