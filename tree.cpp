#include "tree.h"
#include <iostream>
using namespace std;

tree::tree(){Root=new node;}

//a=97 z=122 (-97)
void tree::add_word(string word,string file_name) {
    current_node=Root;
    for(int i=0;i<word.length();i++)
    {   if(current_node->children[(int)word[i]-97]==nullptr)
        {
            current_node->children[(int)word[i]-97]=new node;
            current_node->children[(int)word[i]-97]->name=word[i];
        }
        current_node=current_node->children[(int)word[i]-97];
    }
    if(current_node->children[26]== nullptr)
    {
        current_node->children[26]= new node;
        current_node->children[26]->name = '*';
    }
    current_node=current_node->children[26];
    current_node->files.push(file_name);

}
SetTree<string> tree::get_files(string word) {
    current_node=Root;
    for(int i=0;i<word.length();i++)
    {   if(current_node->children[(int)word[i]-97]==nullptr)
        {
            SetTree<string>a;
            return a;
        }
        current_node=current_node->children[(int)word[i]-97];
    }
    if(current_node->children[26]->name=='*')
    {
        return current_node->children[26]->files;
    }
    else{
        SetTree<string>a;
        return a;
    }
}
void tree::destructor(node* x) {
    for(int i=0;i<27;i++)
    {
       if(x->children[i]!= nullptr)
       {
           destructor(x->children[i]);
       }
    }
    delete x;
}
tree::~tree(){
    this->destructor(Root);
}