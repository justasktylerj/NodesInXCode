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
CTECBinaryTree<Type> :: CTECBinaryTree()
{
    while(root != nullptr)
    {
        remove(root);
    }
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
        TreeNode<Type> * currentNode = root;
        TreeNode<Type> * trailNode;
        
        if(root == nullptr)
        {
            root = new TreeNode<Type>(value);
        }
        else
        {
            while (currentNode != nullptr)
            {
                trailNode = currentNode;
                
                if (currentNode->getValue() < value)
                {
                    currentNode = currentNode->getRightChild();
                }
                else
                {
                    currentNode = currentNode->getLeftChild();
                }
            }
            if(trailNode->getValue() > value)
            {
                trailNode->setLeftChild(new TreeNode<Type>(value, trailNode));
            }
            else
            {
                TreeNode<Type> * insertedNode = new TreeNode<Type>(value, trailNode);
                trailNode->setRightChild(insertedNode);
            }
        }
    }
    return true;

}

template <class Type>
void CTECBinaryTree<Type> :: remove(const Type& value)
{
    TreeNode<Type> * current = root;
    TreeNode<Type> * trailing = current;
    if(!contains(value))
    {
        return
    }
    else
    {
        while(current != nullptr && current->getValue() != value)
        {
            trailing = current;
            if(current->getValue() > value)
            {
                current = current->getLedftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        
        if(current == root)
        {
            remove(root)
        }
        else if (trailing->getValue() > value)
        {
            remove(trailing->getLeftChild
        }
        else
        {
            remove(trailing->getRightChild)
        }
    }
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
    else if(value < currentTree->getValue())
    {
        return contains(value, currentTree->getLeftChild());
    }
    else
    {
        return contains(value, currentTree->getRightChild());
    }
    return false;
}
 
template <class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getRightMostChild(CTECBinaryTree<Type> * leftSubTree)
{
    TreeNode<Type>* rightNode = leftSubTree->getRoot();
    while(rightNode->getRightChild() != nullptr)
    {
        rightNode = rightNode->getRightNode();
    }
    
    return rightNode;
}
        
template <class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getLeftMostChild(CTECBinaryTree<Type> * rightSubTree)
{
    TreeNode<Type>* leftNode = rightSubTree->getRoot();
    while(leftNode->getleftChild() != nullptr)
    {
        leftNode = leftNode->getLeftNode();
    }
            
    return leftNode;
}
        
template <class Type>
void CTECBinaryTree<Type> :: remove(TreeNode<Type> * nodeToRemove)
{
    TreeNode<Type> * current;
    TreeNode<Type> * trailing;
    TreeNode<Type> * temp;
    
    if(nodeToRemove == nullptr)
    {
        cerr << "doh! you cant remove an empty no-existn thing" << endl;
    }
    else if(nodeToRemove->getRightChild() == nullptr && nodeToRemove->getLeftChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = nullptr;
        delete temp;
    }
    else if(nodeToRemove->getRightChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = nullptr;
        delete temp;
    }
    
    else if(nodeToRemove->getLeftChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = nullptr;
        delete temp;
    }
    else
    {
        current = nodeTpRemove->getLeftChild();
        trailing = nullptr;
        
        while(current->getRightChild != nullptr)
        {
            trailing = current;
            current = current-> getRightChild();
        }
        
        nodeToRemove->setValue(current->getValue());
        
        if(trailing == nullptr)
        {
            nodeToRemove->setLeftChild(current->getLeftChld());
        }
        else
        {
            trailing->setRightChild(current->getLeftChild());
        }
        
        delete current;
    }

}
    

        

        
        
        
        
