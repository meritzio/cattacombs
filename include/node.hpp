#ifndef NODE_HPP
#define NODE_HPP

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
            node();
            ///Connect a node up to another node
            void connect(node* node);
            ///Disconnect a node from this node (if the connection exists)
            void disconnect(node* node);
            ///Determine if the node is external
            bool IsExternal();
        private:
            ///The nodes this node is connected to
            node* nodes;
    };
}

#endif //NODE_HPP


