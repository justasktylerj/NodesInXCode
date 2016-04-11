//
//  TreeNode.cpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "TreeNode.h"

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
    this->parent = nullptr;
    
    this->setValue(value);
    this->setParent(parent);
}

template <class Type>
TreeNode<Type> :: getLeftChild()
{
    return this->leftChiild;
}

template <class Type>
TreeNode<Type> :: getRightChild()
{
    return this->rightChild;
}

template <class Type>
TreeNode<Type> :: getParent()
{
    return this->parent;
}

template <class Type>
TreeNode<Type> :: setLeftChild(<#TreeNode<Type> *leftChild#>)
{
    this->leftChild = leftChild;
}

template <class Type>
TreeNode<Type> :: setRightChild(<#TreeNode<Type> *rightChild#>)
{
    this-> rightChild = rightChild;
}

template <class Type>
TreeNode<Type> :: setParent(<#TreeNode<Type> *parent#>)
{
    this-> parent = parent;
}
