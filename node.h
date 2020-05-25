//
// Created by bondo on 10-May-20.
//

#ifndef DS_XML_NODE_H
#define DS_XML_NODE_H
#include <string>
#include "SetTree.h"

using namespace std;
class node {
public:
    char name;
    node* children[27];
    //SetTree<string> files;
    string file ="";
    string last_file="";
    node();
};


#endif //DS_XML_NODE_H
