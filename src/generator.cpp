#include "generator.hpp"

cattacombs::generator::generator()
{
    this->_externalValid = generator::MinRadiusValid;
}

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

void cattacombs::generator::SetExternalNodeValidationFunction(function<bool(volume*, vector3*)> func)
{
    this->_externalValid = func;
}

void cattacombs::generator::PlaceExternalNodes()
{
    volume* v = this->GetExternalGeometry();
    graph*  g = this->GetGraph();
    
    vector<node*> externals = g->GetNodes(false);
    
    for(node* n : externals) { //Randomly position the external nodes on the geometry surfaces
        vector3* v3 = new vector3();
        
        do {
            vector3 randomSurfacePoint = v->GetRandomSurfacePoint(); //Get random surface positions until acceptable
            v3->x = randomSurfacePoint.x;
            v3->y = randomSurfacePoint.y;
            v3->z = randomSurfacePoint.z;
        } while(!this->_externalValid(v, v3));
        
        n->SetPosition(v3);
    }
    
    return;
}

bool cattacombs::generator::MinRadiusValid(volume* v, vector3* v3)
{
    //TODO implemenatation
    // All surface points must be away from each other with the minimum radius specified
    return true;
}

