#include <iostream>
#pragma once

////////////////////////////////////////////////////////////////////
//   Implementation is added to the header file as the compiler   // 
// fires an error with the class template implemented in cpp file //
////////////////////////////////////////////////////////////////////

template <class type>
class TreeNode{
    private:
        type data;
        TreeNode *parent;
        TreeNode *left;
        TreeNode *right;
    public:
        TreeNode(type);
        TreeNode(type,TreeNode<type>*);
        void set(type);
        type get();
        TreeNode<type> *getParent();
        TreeNode<type> *getLeft();
        TreeNode<type> *getRight();
        void setParent(TreeNode<type> *);
        void setLeft(TreeNode<type> *);
        void setRight(TreeNode<type> *);
};

template <class type>
TreeNode<type>::TreeNode(type val){
    data = val;
    parent = NULL;
    left = NULL;
    right = NULL;
}

template <class type>
TreeNode<type>::TreeNode(type val,TreeNode<type> * p){
    data = val;
    parent = p;
    left = NULL;
    right = NULL;
}

template <class type>
void TreeNode<type>::set(type val){
    data = val;
}

template <class type>
type TreeNode<type>::get(){
    return data;
}

template <class type>
TreeNode<type> *TreeNode<type>::getParent(){
    return parent;
}

template <class type>
TreeNode<type> *TreeNode<type>::getLeft(){
    return left;
}

template <class type>
TreeNode<type> *TreeNode<type>::getRight(){
    return right;
}

template <class type>
void TreeNode<type>::setParent(TreeNode<type> *p){
    parent = p;
}

template <class type>
void TreeNode<type>::setRight(TreeNode<type> *r){
    right = r;
}

template <class type>
void TreeNode<type>::setLeft(TreeNode *l){
    left = l;
}

template <class type>
class SetTree{
    private:
        int size_member;
        TreeNode<type> *head;
        bool origin;
    public:
        SetTree();
        SetTree(const SetTree<type>&);
        void push(type);
        int size();
        TreeNode<type>* begin();
        TreeNode<type>* end();
        TreeNode<type>* next(TreeNode<type>*);
        ~SetTree();
};

template <class type>
SetTree<type>::SetTree(){
    origin = 0;
    head = NULL;
    size_member = 0;
}

template <class type>
SetTree<type>::SetTree(const SetTree<type> &old){
    origin = 1;
    head = old.head;
    size_member = old.size_member;
}

template <class type>
void SetTree<type>::push(type data){
    TreeNode<type> *it = head;
    TreeNode<type> *it_late = NULL;
    TreeNode<type> *element;
    if(head == NULL){
        element = new TreeNode<type>(data,it_late);
        head = element;
        size_member++;
    }
    else{
        it_late = it;
        while(it->getLeft() != NULL || it->getRight() != NULL){
            it_late = it;
            if(data == it->get()){
                return;
            }
            if(it->getLeft() == NULL){
                if(data < it->get()) break;
                it = it->getRight();
                it_late = it;
            }else if(it->getRight() == NULL){
                if(data > it->get()) break;
                it = it->getLeft();
                it_late = it;
            }else{
                if(data < it->get()){
                    it = it->getLeft();
                    it_late = it;
                }
                else{
                    it = it->getRight();
                    it_late = it;
                }
            }
        }
        element = new TreeNode<type>(data,it_late);
        if(it->getLeft() == NULL && it->getRight() == NULL){
            if(data < it->get()){
                size_member++;
                it->setLeft(element);
            }
            else if(data > it->get()){
                size_member++;
                it->setRight(element);
            }
        }else if(it->getLeft() == NULL){
            size_member++;
            it->setLeft(element);
        }
        else{
            size_member++;
            it->setRight(element);
        }
    }
}

template <class type>
TreeNode<type>* SetTree<type>::begin(){
    TreeNode<type> *it = head;
    if(it !=NULL) {
        while (it->getLeft() != NULL)
            it = it->getLeft();
    }
    return it;
}

template <class type>
TreeNode<type>* SetTree<type>::end(){
    TreeNode<type> *it = head;
    if(it!=NULL) {
        while (it->getRight() != NULL)
            it = it->getRight();
    }
    return it;
}

template <class type>
int SetTree<type>::size(){
    return size_member;
}

template <class type>
TreeNode<type>* SetTree<type>::next(TreeNode<type>* it){
    if(it->getRight() != NULL){
        it = it->getRight();
        while(it->getLeft() != NULL){
            it = it->getLeft();
        }
        return it;
    }
    while(it->getParent() != NULL){
        if(it->getParent()->get() > it->get())
            return it->getParent();
        it = it->getParent();
    }
    return NULL;
}

template <class type>
SetTree<type>::~SetTree() {
    if(!origin){
        TreeNode<type> *it = this->begin();
        if (it != NULL) {
            while (it->getParent() != NULL || it->getRight() != NULL) {
                while (it->getRight() != NULL) {
                    it = it->getRight();
                    while (it->getLeft() != NULL)
                        it = it->getLeft();
                }
                it = it->getParent();
                if (it->getLeft() == NULL) {
                    delete it->getRight();
                    it->setRight(NULL);
                } else {
                    delete it->getLeft();
                    it->setLeft(NULL);
                }
            }
            delete head;
            head = NULL;
        }
    }
}
