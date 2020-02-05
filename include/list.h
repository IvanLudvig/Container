#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <node.h>

class list
{
    public:
        list();
        void add(int data);
        void addToFront(int data);
        void insertAt(int data, int index);
        void print();
        int getLength();
        node* findNode(int data);
        node* getByIndex(int index);
        ~list();

    private:
        int length;
        node* root;
};


#endif // LIST_H
