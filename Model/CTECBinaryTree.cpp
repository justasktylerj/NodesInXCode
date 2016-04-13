//
//  CTECBinaryTree.cpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECBinaryTree.h"
using namespace CTECData;

template <class Type>
void CTECBinaryTree:: inOrderTraversal<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        inOrderTraversal(currentNode->getLeftChild());
        cout << currentNode->getValue() << " " ;
        inOrderTraversal(currentNode->getRightChild());
    }
}

template <class Type>
void CTECBinaryTree:: postOrderTraversal<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        cout << currentNode->getValue() << " " ;
        postOrderTraversal(currentNode->getLeftChild());
        postOrderTraversal(currentNode->getRightChild());
    }
}

template <class Type>
void CTECBinaryTree:: preOrderTraversal<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        preOrderTraversal(currentNode->getLeftChild());
        preOrderTraversal(currentNode->getRightChild());
        cout << currentNode->getValue() << " " ;
    }
}

template <class Type>
void CTECBinaryTree:<Type> :: getSize()
{
    size = 0;
    calculateSize(root);
    return size;
    
}

        
template <class Type>
void CTECBinaryTree:<Type> :: calculateSize(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        postorderTraversal(currentNode->getLeftChild());
        postorderTraversal(currentNode->getRightChild());
        size++;
    }
            
}
