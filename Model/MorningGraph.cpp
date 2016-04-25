//
//  MorningGraph.cpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 4/25/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "MorningGraph.hpp"
using namespace CTECData;

template <class Type>
const int MorningGraph<Type> :: MAXIMUM;

template <class Type>
const MorningGraph<Type> :: addEdge(int source, int target)
{
    assert(source < size());
    assert(target < size());
    edges[source][target] = true;
    
}

template <class Type>
void MorningGraph<Type> :: addVertex(const Type& vertexLabel)
{
    int newVertexNumber;
    int otherNumber;
    
    assert(size() < MAXIMUM);
    
    newVertexNumber = manyVertices;
    ++manyVertices;
    
    for(otherNumber = 0; otherNumber < manyVertices; manyVertices++)
    {
        edges[otherNumber][newVertexNumber] = false;
        edges[newVertexNumber][otherNumber] = false;
    }
    
    labels[newVertexNumber] = vertexLabel;
    
}


template <class Type>
bool MorningGraph<Type> :: isEdge(int source, int target) const
{
    bool connected = false;
    
    assert(source < size() && target < size());
    connected = edges [source][target];
    
    return connected;
    
}

template <class Type>
Type& MorningGraph<Type> :: operator[](int vertex)
{
    assert (vertex < size());
    return labels[vertex];
}

template <class Type>
Type MorningGraph<Type> :: operator[](int vertex) const
{
    assert (vertex < size());
    return labels[vertex];
}

template <class Type>
std::set<int> MorningGraph<Type> neighbors(int vertex) const
{
    std::set<int> answer;
    assert(vertex < size()):
    
    for (int index=0; index < size(); index++)
    {
        if(edges[vertex][index])
        {
            answer.insert(index);
        }
    }
    return answer;
}

template <class Type>
void MorningGraph:: removeEdge(int source, int target)
{
    assert(source < size() && target 
}



