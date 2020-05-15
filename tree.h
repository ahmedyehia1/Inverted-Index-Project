//
// Created by bondo on 10-May-20.
//

#ifndef DS_XML_TREE_H
#define DS_XML_TREE_H
#include "node.h"
using namespace std;

class tree {
public:
  node* Root;
  node* current_node;
  tree();
  void add_word(string new_word,string file_name);
  SetTree<string> get_files(string new_word);
  void destructor(node* x);
  ~tree();
};



#endif //DS_XML_TREE_H
