#ifndef GENERATOR_H
#define GENERATOR_H

#include "volume.hpp"
#include "graph.hpp"

namespace cattacombs
{
    /**
     *  The main class for generating procedural asset geometry.
     *  
     */
    class generator
    {
        public:
            ///Provide the external geometry for node placement
            void SetExternalGeometry(volume* v);
            ///Get the external geometry used for node placement
            volume* GetExternalGeometry();
            ///Set the graph used for node placement
            void SetGraph(graph* g);
            ///Get the graph used for node placement
            graph* GetGraph();
            
        protected:
            
        private:
            volume* _externalGeometry;
            graph* _graph;
    };
}

#endif //GENERATOR_H
