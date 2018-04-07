#ifndef GENERATOR_H
#define GENERATOR_H

#include <functional>
#include "volume.hpp"
#include "vector3.hpp"
#include "graph.hpp"
#include "node.hpp"

using namespace std;

namespace cattacombs
{
    /**
     *  The main class for generating procedural asset geometry.
     *  
     */
    class generator
    {
        public:
            generator();
            ///Provide the external geometry for node placement
            void SetExternalGeometry(volume* v);
            ///Get the external geometry used for node placement
            volume* GetExternalGeometry();
            ///Set the graph used for node placement
            void SetGraph(graph* g);
            ///Get the graph used for node placement
            graph* GetGraph();
            ///Set the function that determines the external node placement is satisfactory
            void SetExternalNodeValidationFunction(function<bool(volume*, vector3*)> func);
            ///Place the external nodes on the geometry suface
            void PlaceExternalNodes();
            ///Default function for external node placement
            static bool MinRadiusValid(volume* v, vector3* v3);
            
        protected:
            
        private:
            volume* _externalGeometry;
            graph* _graph;
            function<bool(volume*, vector3*)> _externalValid;
    };
}

#endif //GENERATOR_H
