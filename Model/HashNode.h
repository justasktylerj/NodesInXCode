//
//  HashNode.hpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 5/9/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef HashNode_h
#define HashNode_h

#include <iostream>

template <class Type>
class HashNode
{
private:
    int key;
    Type value;
public:
    HashNode();
    HashNode(int key, const Type & value);
    void setKey(int key);
    void setValue(const Type & value);
    int getKey();
    Type getValue();
    
};

#endif /* HashNode_h */