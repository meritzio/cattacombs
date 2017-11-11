#include "generator.hpp"


void cattacombs::generator::SetExternalGeometry(volume* v)
{
    _externalGeometry = v;
}

cattacombs::volume* cattacombs::generator::GetExternalGeometry()
{
    return _externalGeometry;
}

void cattacombs::generator::SetGraph(graph* g)
{
    _graph = g;
}

cattacombs::graph* cattacombs::generator::GetGraph()
{
    return _graph;
}

