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
    const int base = 16;
    char** nodeNames = new char*[iL];
    char hexBase[] = "0123456789ABCDEF";
    
    //Populate the dict with node name associations as hexadecimal base
    for(int i = 0; i < iL; i++) {
        
        vector<char> chars;
        chars.push_back('\0');
        
        int val = i;
        do {
            char alfa = hexBase[val % base];
            chars.push_back(alfa);
            val /= base;
        } while(val > 0);
        cout << endl;

        int jL = chars.size();
        char* name = new char[jL];
        for(int j = 0; j < jL; j++)
            *(name + jL - j - 1) = chars[j];
        
        nodeNames[i] = name;
        nameDict[nodes[i]] = name;
    }
    
    //Now display all the node relationships
    for(node* n : nodes) {
        
        char* name = nameDict[n];
        auto connections = n->GetConnections();
        cout << '[';
        while(*name) {
            cout << *name;
            name++;
        }
        cout << "] { ";
        
        for(node* connection : connections) {
            name = nameDict[connection];
            while(*name) {
                cout << *name;
                name++;
            }
            cout << ' ';
        }
        
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


