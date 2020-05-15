//
// Created by bondo on 10-May-20.
//

#include "node.h"
node::node(){
    for(int i=0;i<27;i++)
    {
        children[i]=nullptr;
    }
}