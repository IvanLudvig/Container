#include "node.h"

template<typename T>
node<T>::node(const T &value)
{
    this->value = value;
    next = NULL;
}

template<typename T>
void node<T>::append(const T &value)
{
    node<T> *element = new node<T>(value);
    node<T> *current = this;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = element;
}

template<typename T>
bool node<T>::exists(const T &value)
{
    node<T> *current = this;
    while (current != NULL)
    {
        if (current->value == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
node<T> *node<T>::getNext() const
{
    return this->next;
}

template<typename T>
T node<T>::getValue() const
{
    return value;
}

template<typename T>
node<T>::~node()
{

}

