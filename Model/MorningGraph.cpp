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
std::set<int> MorningGraph<Type> :: neighbors(int vertex) const
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
void MorningGraph<Type> :: removeEdge(int source, int target)
{
    assert(source < size() && target
}
           
template <class Type>
void MorningGraph<Type> :: depthFirstTraversal(MorningGraph<Type> currentGraph, int vertex, bool * markedVertices)
{
    bool markedVertices[MAXIMUM];
    
}

           
template <class Type>
void MorningGraph<Type> :: depthFirstTraversal(MorningGraph<Type> currentGraph, int vertex, bool * markedVertices)
{
    std::set<int> connections = currentGraph.neighbors(vertex);
    std::set<int>::iterator setIterator;
        
/Users/tjar2074/Documents/C++ projects/NodesInXCode/Model/TreeNode.h    markedVertices[vertex] = true;
    cout << currentGraph[vertex] << endl;
        
    for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
    {
        if(!markedVertices[*setIterator])
        {
            depthFirstTraversal(currentGraph, *setIterator, markedVertices);
        }
    }
}
           
           

           template <class Type>
void MorningGraph<Type> :: breadthFirstTraversal(MorningGraph<Type> currentGraph, int vertex)
{
    bool markedVertices[MAXIMUM];
    std::set<int> connections;
    std::set<int>::iterator setIterator;
    std::queue<int> vertesQueue;
    assert(vertex < currentGraph.size());
    
    std::fill_n(markedVertices, currentGraph.size(), false);
    markedVertices[vertex] = true;
    cout << currentGraph[vertex] << endl;
    vertexQueue.push(vertex);
    while (!vertexQueue.empty())
    {
        connections = currentGraph.neighbors(vertexQueue.front());
        vertexQueue.pop();
        
        for(setIterator = connections.begon(); setIterator != connections.end(); setIterator++)
        {
            if(!markedVertices[*markedVertices])
            {
                markedVertices[*setIterator] = true;
                cout << currentGraph[*setIterator] << endl;
                vertexQueue.push(*setIterator);
            }
        }
    }
}




