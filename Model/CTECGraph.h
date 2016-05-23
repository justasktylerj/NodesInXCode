//
//  MorningGraph.hpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 4/25/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECGraph_h
#define CTECGraph_h

#include <set>


template <class Type>
class Graph
{
private:
    static const int MAXIMUM = 20;
    bool edges [MAXIMUM][MAXIMUM]; //This is the adjacency matrix.
    Type labels [MAXIMUM];
    int manyVertices;
    void depthFirstTraversal(Graph<Type> currentGraph, int vertex, bool * markedVertices);
public:
    Graph();
    virtual ~Graph();
    
    void addVertex(const Type & label);
    void addEdge(int source, int target);
    void removeEdge(int source, int target);
    Type & operator [] (int vertex);
    int size() const;
    bool isEdge(int source, int target) const;
    std :: set<int> neighbors(int vertex) const;
    Type operator [] (int vertex) const;
    void depthFirstTraversal(Graph<Type> currentGraph, int vertex);
    void breadthFirstTraversal(Graph<Type> currentGraph, int vertex);
};

#endif /* CTECGraph_h */
