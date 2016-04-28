//
//  TreeNode.cpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "TreeNode.h"
using namespace CTECData;

template <class Type>
TreeNode<Type> :: TreeNode() : CTECData::Node<Type>()
{
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->parent = nullptr;
}

template <class Type>
TreeNode<Type> :: TreeNode(const Type& value) : CTECData::Node<Type>(value)
{
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->parent = nullptr;
    
    this->setValue(value);
}

template <class Type>
TreeNode<Type> :: TreeNode(const Type& value, TreeNode<Type> * parent) : CTECData::Node<Type>(value)
{
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    
    this->setValue(value);
    this->setParent(parent);
}

template <class Type>
void TreeNode<Type> :: setLeftChild(TreeNode<Type> * leftChild)
{
    this->leftChild = leftChild;
}

template <class Type>
TreeNode<Type> * TreeNode<Type> :: getLeftChild()
{
    return this->leftChild;
}