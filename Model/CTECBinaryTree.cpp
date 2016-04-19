//
//  CTECBinaryTree.cpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECBinaryTree.h"
using namespace CTECData;
using namespace std;


template <class Type>
CTECBinaryTree<Type> :: CTECBinaryTree()
{
    root = nullptr;
    height = 0;
    balanced = true;
    size = 0;
}

template <class Type>
bool CTECBinaryTree:: insert(const Type& value)
{
    if(contains(value))
    {
        return false;
    }
    else
    {
        if(value < root->getValue())
        {
            insert(value, root->getLeftChild())
        }
        else
        {
            insert(value, root->getRightChild())
        }
        return true;
    }
}

template <class Type>
void CTECBinaryTree<Type> :: insert(const Type& value, CTECBinaryTree<Type> * currentTree)
{
    
}

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
        
template <class Type>
bool CTECBinaryTree:<Type> :: contains(Type value, CTECBinaryTree<Type> currentTree)
{
    if(currentTree == nullptr)
    {
        return false;
    }
    
    if(root->getValue == value)
    {
        return true;
    }
    else if(value < currentTree->getRoot()->getValue())
    {
        return contains(value, currentTree->getRoot()->getLeftChild());
    }
    else
    {
        return contains(value, currentTree->getRoot()->getRightChild());
    }
    return false;
}
 
template <class Type>
void CTECBinaryTree:<Type> :: insert(const Item& entry)
{
    root_ptr = new binary_tree_node<Item>(entry);
    cursor = cursor->left;
}

template <class Type>
bool CTECBinaryTree:<Type> :: erase_one(const Item& target)
{
    
}
      

        

        
        
        
        
