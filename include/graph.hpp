#ifndef GRAPH_H
#define GRAPH_H

#include "node.hpp"
#include <vector>
#include <random>
#include <stdexcept>

using namespace std;

namespace cattacombs
{
    /**
     *  The graph that holds all nodal connections
     *  
     */
    class graph
    {
        class connectionExc;
        
        public:
            ///Construct a graph
            graph();
            ///Deallocate the graph and its child nodes
            ~graph();
            
            ///Get a representational state of the nodes
            vector<node*> GetNodes();
            ///Add a dynamically allocated node to the graph
            void AddNode(node* n);
            
            ///Create a dynamically allocated graph from random, given a number of nodes to formulate the connections 
            /// (connections within reason)
            static graph* FromRandom(const int nInnerNodes, const int nOuterNodes, 
                const int maxInnerConnections=5, const int maxOuterconnections=2);
            
            ///Outline the graph topology into the console
            void PrintTopology();
                        
        private:
            ///The list of nodes that make up the graph
            vector<node*> nodes;
            ///A convenience method for obtaining a random number in a range
            int randN(const int max);
            ///The generator for making random quantities
            default_random_engine *randEngine;
            
            class connectionExc : invalid_argument
            {
                public:
                    ///Raise an error about maximum connections being reached in a graph
                    connectionExc() : 
                    invalid_argument(
                    "All internal connections have been filled up! Not enough connectors to complete graph"
                    ) {};
            };
    };
}

#endif //GRAPH_H
