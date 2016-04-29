//
//  MorningGraph.hpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 4/25/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECGraph_hpp
#define CTECGraph_hpp
#include <set>

namespace CTECData
{
    template <class Type>
    class CTECGraph
    {
    private:
        static const int MAXIMUM = 20;
        bool edges [MAXIMUM][MAXIMUM];
        Type labels [MAXIMUM];
        int manyVertices;
        void depthFirstTraversal(CTECGraph<Type> currentGraph, int vertex, bool * markedVertices);
        
    public:
        CTECGraph();
        virtual ~CTECGraph();
        
        void addVertex(const Type& label);
        void addEdge(int source, int target);
        void removeEdge(int source, int target);
        Type& operator [] (int vertex);
        int size() const;
        bool isEdge(int source, int target)const;
        std::set<int> neighbors(int vertex) const;
        Type operator [](int vertex) const;
        void depthFirstTraversal(CTECGraph<Type> currentGraph, int vertex);
        void breadthFirstTraversal(CTECGraph<Type> currentGraph, int vertex);
    };
}

#endif /* MorningGraph_hpp */
