#ifndef NODE_H
#define NODE_H
#include <iostream>

class node
{
    public:
        node(int data);
        virtual ~node();
        void push(int data);
        void append(int data);
        node* getNext();
        int getData();
        node* findElement(int data);

    private:
        node* next;
        int data;
};

#endif // NODE_H
