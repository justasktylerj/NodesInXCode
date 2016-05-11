//
//  HashNode.hpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 5/9/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef HashNode_h
#define HashNode_h

#include <stdio.h>

namespace CTECData
{
    template <class Type>
    class HashNode
    {
  
    private:
        int key;
        
        Type value;
    public:
        HashNode()
        void setKey(int key);
        void setValue(Type value);
        int getKey();
        Type getValue();
    };
}

#endif /* HashNode_h */
