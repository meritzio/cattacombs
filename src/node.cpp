#include "node.hpp"

using namespace cattacombs;

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

vector<node*> cattacombs::node::GetConnections()
{
    int iL = nodes.size();
    vector<node*> array;
    
    for(int i = 0; i < iL; i++)
        array.push_back(nodes[i]);
    
    return array;
}
