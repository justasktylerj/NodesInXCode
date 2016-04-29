#include "CTECGraph.h"
#include <iostream>
#include <queue>
using namespace std;
using namespace CTECData;

template <class Type>
const int CTECGraph<Type> :: MAXIMUM;

template <class Type>
CTECGraph<Type> :: CTECGraph()
{
    this->manyVertices = 0;
}

template <class Type>
CTECGraph<Type> :: ~CTECGraph()
{

}

template <class Type>
int CTECGraph<Type> :: size() const
{
    return manyVertices;
}

template <class Type>
void CTECGraph<Type> :: addEdge(int source, int target)
{
    assert(source < size());
    assert(target < size());
    edges[source][target] = true;
    
}

template <class Type>
void CTECGraph<Type> :: addVertex(const Type& vertexLabel)
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
bool CTECGraph<Type> :: isEdge(int source, int target) const
{
    bool connected = false;
    
    assert(source < size() && target < size());
    connected = edges [source][target];
    
    return connected;
    
}

template <class Type>
Type& CTECGraph<Type> :: operator[](int vertex)
{
    assert (vertex < size());
    return labels[vertex];
}

template <class Type>
Type CTECGraph<Type> :: operator[](int vertex) const
{
    assert (vertex < size());
    return labels[vertex];
}

template <class Type>
std::set<int> CTECGraph<Type> :: neighbors(int vertex) const
{
    std::set<int> answer;
    assert(vertex < size());
    
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
void CTECGraph<Type> :: removeEdge(int source, int target)
{
    assert(source < size() && target);
}
           
template <class Type>
void CTECGraph<Type> :: depthFirstTraversal(CTECGraph<Type> currentGraph, int vertex)
{
    bool markedVertices[MAXIMUM];
    assert (vertex < currentGraph.size());
    std :: fill_n(markedVertices, currentGraph.size(), false);
    depthFirstTraversal(currentGraph, vertex, markedVertices);
    
}

           
template <class Type>
void CTECGraph<Type> :: depthFirstTraversal(CTECGraph<Type> currentGraph, int vertex, bool * markedVertices)
{
    std::set<int> connections = currentGraph.neighbors(vertex);
    std::set<int>::iterator setIterator;
        
    markedVertices[vertex] = true;
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
void CTECGraph<Type> :: breadthFirstTraversal(CTECGraph<Type> currentGraph, int vertex)
{
    bool markedVertices[MAXIMUM];
    std :: set<int> connections;
    std :: set<int>::iterator setIterator;
    std :: queue<int> vertexQueue;
    assert(vertex < currentGraph.size());
    
    std::fill_n(markedVertices, currentGraph.size(), false);
    markedVertices[vertex] = true;
    cout << currentGraph[vertex] << endl;
    vertexQueue.push(vertex);
    while (!vertexQueue.empty())
    {
        connections = currentGraph.neighbors(vertexQueue.front());
        vertexQueue.pop();
        
        for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
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




