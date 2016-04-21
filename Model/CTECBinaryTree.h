//
//  CTECBinaryTree.hpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECBinaryTree_h
#define CTECBinaryTree_h

#include "TreeNode.cpp"

template <class Type>
class CTECBinaryTree
{
private:
    TreeNode<Type> * root;
    int height;
    bool balanced;
    bool contains(Type value, CTECBInaryTree<Type> * currentTree);
    void calculateSize(TreeNode<Type> * currentNode);
    TreeNode<Type> * getRightMostChild(CTECBinaryTree * leftSubTree)
    TreeNode<Type> * getLeftMostChild(CTECBinaryTree * rightSubTree)
    void remove(TreeNode<Type> * currentNode)
public:
    CTECBinaryTree():
    ~CTECBinaryTree():
    bool insert(const Type& value);
    bool contains(Type value):
    Type remove(const Type& value);
    int getHeight();
    int getSize();
    bool isBalanced();
    TreeNode<Type> * getRoot();
    void inOrderTraversal(TreeNode<Type> * currentNode);
    void postOrderTraversal(TreeNode<Type> * currentNode);
    void preOrderTraversal(TreeNode<Type> * currentNode);
    bool erase_one(const Type& value);
};

#endif /* CTECBinaryTree_hpp */
