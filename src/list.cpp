#include "list.h"

using namespace std;

template<typename T>
list<T>::list()
{

}

template<typename T>
list<T>::list(const list<T> &l)
{
    if(root==NULL)
    {
        *root = *l.root;
        length = l.length;
    }
}

template<typename T>
void list<T>::insert(const T &value)
{
    if(length==0)
    {
        root = new node<T>(value);
    }else
    {
        root->append(value);
    }
    length++;
}

template<typename T>
bool list<T>::exists(const T &value) const
{
    if(length==0)
    {
        return false;
    }else
    {
        return root->exists(value);
    }
}

template<typename T>
void list<T>::remove(const T &value)
{
    if(exists(value))
    {
        if (length == 0)
        {
            return;
        }
        node<T> *element = root;
        if(root->getValue()==value){
            node<T> *temp = root->next;
            delete root;
            root = temp;
            length--;
            return;
        }
        for (unsigned int i = 0; i < length - 1; i++)
        {
            std::cout << i << std::endl;
            if (element->next->getValue() != value)
            {
                element = element->next;
                continue;
            }
            node<T> *temp = element->next->next;
            delete element->next;
            element->next = temp;
            length--;
            return;
        }
    }
}

template<typename T>
void list<T>::print()
{
    if(length==0)
    {
        return;
    }
    node<T>* current = root;
    while(current->next!=NULL)
    {
        cout<<current->getValue()<<endl;
        current = current->next;
    }
    cout<<current->getValue()<<endl;
}

template<typename T>
int list<T>::getLength()
{
    return length;
}

template<typename T>
void list<T>::operator=(const list<T> &l)
{
    //delete root;
    root = l.root;
    length = l.length;
}

template<typename T>
list<T>::~list()
{
    node<T>* current = root;
    while(current!=NULL)
    {
        node<T>* temp = current->next;
        delete current;
        current = temp;
    }
    delete current;
}
