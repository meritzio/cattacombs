#include "node.hpp"

cattacombs::node::node(bool entryPoint)
{
    this->entryPoint = entryPoint;
}

void cattacombs::node::connect(node* node)
{
    this->nodes.push_back(node);
    node->nodes.push_back(this);
}

int cattacombs::node::connections()
{
    return nodes.size();
}

void cattacombs::node::disconnect(node* node)
{
    this->nodes.remove(node);
    node->nodes.remove(this);
}

bool cattacombs::node::EntryPoint()
{
    return entryPoint;
}


