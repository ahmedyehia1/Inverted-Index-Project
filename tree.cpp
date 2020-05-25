#include "tree.h"
#include <iostream>
#include <cctype>
#include <sstream>
#include <algorithm>
using namespace std;

tree::tree(){Root=new node;}

//a=97 z=122 (-97)
void tree::add_word(string word,string file_name) {
    current_node=Root;
    //unique_words.push(word);
    for(int i=0;i<word.length();i++)
    {   if(word[i]>96&&word[i]<123) {
            if (current_node->children[(int) word[i] - 97] == nullptr) {
                current_node->children[(int) word[i] - 97] = new node;
                current_node->children[(int) word[i] - 97]->name = word[i];
            }
            current_node = current_node->children[(int) word[i] - 97];
        }
    }
    if(current_node->children[26]== nullptr)
    {
        current_node->children[26]= new node;
        current_node->children[26]->name = '*';
    }
    current_node=current_node->children[26];
    //current_node->files.push(file_name);
    if(current_node->last_file != file_name)
    {
        if(current_node->file=="")
        {
            current_node->file+=file_name;
        }
        else
        {
            current_node->file+=", "+file_name;
        }
        current_node->last_file=file_name;
    }

}
string tree::get_files(string word) {
    current_node=Root;
    for(int i=0;i<word.length();i++)
    { if(word[i]>96&&word[i]<123) {
            if (current_node->children[(int) word[i] - 97] == nullptr) {
                //SetTree<string> a;
                return "";
            }
            current_node = current_node->children[(int) word[i] - 97];
        }
    }

    if(current_node->children[26]!=nullptr&&current_node->children[26]->name=='*')
    {
        return current_node->children[26]->file;
    }
    else{
        //SetTree<string>a;
        return "";
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
void tree::tokenize(string fileData,string file_name){
    stringstream stream(fileData); 
    string chunk,tmp = "";
    while(getline(stream, chunk, ' ')) {
        tmp = "";
        auto a = 0;
        auto b = chunk.length()-1;
        while(ispunct(chunk[a]) && a<b) a++;
        while(ispunct(chunk[b]) && a<=b) b--;
        chunk = chunk.substr(a,b-a+1);
        for(int i=0,l=chunk.length();i<l;i++){
            if(chunk[i]>0&&chunk[i]<255) tmp += tolower(chunk[i]);
            else if(chunk[i] == -103) tmp += 39;
        }
        if(tmp != "") this->add_word(tmp,file_name);
    }
}
