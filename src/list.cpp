#include "list.h"

using namespace std;

list::list()
{
    length = 0;
}

int list::getLength()
{
    return length;
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
            current = current->getNext();
            i++;
        }
        return current;
    }
}

void list::add(int data)
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
            current = current->getNext();
            i++;
        }
        current->push(data);
        length++;
    }
}

void list::print()
{
    node* current = root;
    while(current->getNext()!=NULL)
    {
        cout<<current->getData()<<endl;
        current = current->getNext();
    }
    cout << current->getData() << endl;
}

list::~list()
{
    delete root;
}
