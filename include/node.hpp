#ifndef NODE_HPP
#define NODE_HPP

namespace cattacombs
{
    /** 
     *  Represents a central point leading to different branches, or the outside of the catacombs.
     *  This is the base class which internal and external nodes inherit from.
     */
    class node
    {
        public:
            ///The nodes this node is connected to
            node* nodes;
        protected:
            ///Constructs a new node
            node();
    };
}

#endif //NODE_HPP


