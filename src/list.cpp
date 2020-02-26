#include "../include/list.h"

using namespace std;

list::list()
{
    length = 0;
}

int list::getLength()
{
    return length;
}

bool list::exists(int value)
{
    if(length==0)
    {
        return false;
    }else
    {
        return root->exists(value);
    }
}

node* list::findNode(int data)
{
    if(length==0)
    {
        return NULL;
    }else
    {
        return root->findElement(data);
    }
}

node* list::getByIndex(int index)
{
    if((index<0)||(index>=length))
    {
        return NULL;
    }else
    {
        node* current = root;
        int i = 0;
        while(i<index)
        {
            current = current->next;
            i++;
        }
        return current;
    }
}

void list::insert(int data)
{
    if(length==0)
    {
        root = new node(data);
    }else
    {
        root->append(data);
    }
    length++;
}

void list::addToFront(int data)
{
    if(length==0)
    {
        root = new node(data);
    }else
    {
        root->push(data);
    }
    length++;
}

void list::insertAt(int data, int index)
{
    if((index<0)||(index>length))
    {
        cout<<"error"<<endl;
    }else
    {
        node* current = root;
        int i = 0;
        while(i<index)
        {
            current = current->next;
            i++;
        }
        current->push(data);
        length++;
    }
}

void list::remove(int value)
{
    if(length==0)
    {
        return;
    }
    node* element = root;
    while(element->next->getData()!=value)
    {
        element = element->next;
    }
    node* temp = element->next->next;
    delete element->next;
    element->next = temp;
}

void list::removeAt(int index)
{
    node* element = root;
    if(index == 0)
    {
        root = element->next;
    }
    for(int i = 0; i < index-1; i++)
    {
        element = element->next;
    }
    node* temp = element->next->next;
    delete element->next;
    element->next = temp;
}

void list::print()
{
    node* current = root;
    while(current->next!=NULL)
    {
        cout<<current->getData()<<endl;
        current = current->next;
    }
    cout<<current->getData()<<endl;
}

list::~list()
{
    node* current = root;
    while(current!=NULL)
    {
        node* temp = current->next;
        delete current;
        current = temp;
    }
    delete current;
}
