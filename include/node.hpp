#ifndef NODE_HPP
#define NODE_HPP

#include "xvector.hpp"

using namespace std;

namespace cattacombs
{
    /** 
     *  Represents a central point leading to different branches, or the outside of the catacombs.
     *
     */
    class node
    {
         public:
            ///Constructs a new node
            node(bool entryPoint=false);
            ///Connect a node up to another node
            void connect(node* node);
            ///Disconnect a node from this node (if the connection exists)
            void disconnect(node* node);
            ///Determine if the node is an entrance/exit point
            bool EntryPoint();
            ///The number of connections the node has made
            int connections();
            ///Get the nodes this node is connected to
            vector<node*> GetConnections();
            
        private:
            ///The child nodes this node is connected to
            xvector<node*> nodes;
            ///Whether the node is an entry point
            bool entryPoint;
    };
}

#endif //NODE_HPP


