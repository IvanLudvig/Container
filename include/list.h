#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "../src/node.cpp"
#include "Container.h"

class list : public Container
{
    public:
        list();
        void insert(int value);
        bool exists(int value);
        void remove(int value);
        void addToFront(int value);
        void insertAt(int value, int index);
        void removeAt(int index);
        void print();
        int getLength();
        node* findNode(int value);
        node* getByIndex(int index);
        virtual ~list();

    private:
        int length;
        node* root;
};


#endif // LIST_H
