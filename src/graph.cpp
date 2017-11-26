#include "graph.hpp"
#include "xvector.hpp"

#include <chrono>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;
using namespace cattacombs;

cattacombs::graph::graph()
{
    auto seed = chrono::system_clock::now().time_since_epoch().count();
    this->randEngine = new default_random_engine(seed);
}

cattacombs::graph::~graph()
{
    int nNodes = nodes.size();

    for(int i = 0; i < nNodes; i++)
        delete nodes[i];
    
    nodes.clear();
    
    delete randEngine;
}

vector<node*> cattacombs::graph::GetNodes()
{
    int iL = nodes.size();
    vector<node*> nodeArray;
    
    for(int i = 0; i < iL; i++)
        nodeArray.push_back(nodes[i]);
    
    return nodeArray;
}


void cattacombs::graph::AddNode(node* n)
{
    nodes.push_back(n);
}

cattacombs::graph* cattacombs::graph::FromRandom(
const int nInnerNodes, const int nOuterNodes,
const int maxInnerConnections, const int maxOuterConnections)
{
    graph* g = new graph();
    
    xvector<node*> internals, externals,
                   unvisited,   visited;
    
    //Dynamically allocate the nodes
    for(int i =0; i < nOuterNodes; i++) {
        node* n = new node(true);
        externals.push_back(n);
        g->AddNode(n);
    }
    
    for(int i = 0; i < nInnerNodes; i++) {
        node* n = new node();
        internals.push_back(n);
        g->AddNode(n);
    }
    
    //Mark all internal nodes as unvisited
    for(node* in : internals)
        unvisited.push_back(in);
    
    //Now make random procedural graph connections
    for(node* ex : externals) {
        int connections = g->randN(maxOuterConnections) + 1; //Random number of internal connections, with at least one
        for(int i = 0; i < connections; i++) {
            //Select a random internal node to connect
            node* in;
            xvector<node*> attempted;
            
            do { //Check it hasn't ran out of connectors
                in = internals.random();
                attempted.push_unique(in);
                
                if(attempted.size() == internals.size())
                    throw connectionExc();

            } while(in->connections() >= maxInnerConnections);
            
            ex->connect(in);
            
            //Mark internal node as visited if in the list
            if(unvisited.remove(in))
                visited.push_unique(in);
        }
    }
    
    //Create an internal graph that only produces one tree (no foresting)
    //Implemented by making sure all nodes are visited regardless of looping
    while(unvisited.size() > 0) {
        node* n = unvisited.dequeue(); //Treat unvisited as a queue
        node* connection;              //Try connect to a visited node
        xvector<node*> attempted;
        
        do {
            connection = visited.random();
            attempted.push_unique(connection);
            
            if(attempted.size() == internals.size())
                throw connectionExc();
        } while(connection->connections() >= maxInnerConnections);
        
        n->connect(connection); //Connect to random internal visited node
        
        unvisited.remove(n); //Mark visited
        visited.push_unique(n);
    }
    
    //Finally, add the final random connections aside from tree duty connections
    for(node* n : internals) {
        int duty  = n->connections() - g->randN(maxInnerConnections); //The remaining connections to make
        if(duty < 0) continue;
               
        while(duty > 0) { //Connect to any free (this time self included)
            node* randNode;
            xvector<node*> attempted;
            
            do {
                randNode = internals.random();
                attempted.push_unique(randNode);
                
                if(attempted.size() == internals.size())
                    throw connectionExc();
                
            } while(randNode->connections() >= maxInnerConnections);
            
            duty--;
        }
    }
    
    return g;
}


void cattacombs::graph::PrintTopology()
{
    map<node*, char*> nameDict;
    int iL = nodes.size();
    const int base = 26;
    char** nodeNames = new char*[iL];
    
    //Populate the dict with node name associations as alphanumeric base
    for(int i = 0; i < iL; i++) {
        
        int charSize = (int)(log10((float)(i+1))/log10((float)base)) + 1; //Length of chars
        char* chars = new char[charSize]; 
        
        int value = i;
        
        for(int j = 0; j < charSize; j++) {
            *(chars +j) = 'a' + (char)(value % base);
            value /= base;
        }
        
        nodeNames[i] = chars;
        nameDict[nodes[i]] = chars;
    }
    
    //Now display all the node relationships
    for(node* n : nodes) {
        
        char* name = nameDict[n];
        auto connections = n->GetConnections();
        cout << '[' << *name << "] { ";
        
        for(node* connection : connections)
            cout << *(nameDict[connection]) << ' ';
        
        cout << '}' << endl;
    }
    
    delete[] nodeNames;
}


int cattacombs::graph::randN(const int max)
{
    float _max = randEngine->max(),
          min = randEngine->min();
    
    return max * ((float)((*randEngine)()) - min) / (float) (_max - min);
}


