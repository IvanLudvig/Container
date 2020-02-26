#include "../include/node.h"

node::node(int data)
{
    this->data = data;
    next = NULL;
}

void node::push(int data)
{
    node* element = new node(this->data);
    element->next = this->next;
    this->next = element;
    this->data = data;
}

void node::append(int data)
{
    node* element = new node(data);
    node* current = this;
    while(current->next!=NULL)
    {
        current = current->next;
    }
    current->next = element;
}

node* node::findElement(int data)
{
    node* current = this;
    while(current->getData()!=data)
    {
        current = current->getNext();
    }
    return current;
}

bool node::exists(int data)
{
    node* current = this;
    while(current->next!=NULL)
    {
        if(current->data==data)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

node* node::getNext()
{
    return this->next;
}

int node::getData()
{
    return data;
}

node::~node(){

}

