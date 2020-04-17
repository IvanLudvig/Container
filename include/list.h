#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "Container.h"
#include <iterator>

template<typename T>
class list : public Container<T>
{
private:
    unsigned int length = 0;
    node<T> *root;

public:
    list();

    list(const list<T> &l);

    void insert(const T &value);

    bool exists(const T &value) const;

    void remove(const T &value);

    void print();

    int getLength();

    void operator=(const list<T> &l);

    ~list();

    class iterator
    {
        friend class list<T>;

    private:
        node<T> *nodePtr;

    public:
        iterator() : nodePtr(NULL)
        {}

        iterator(node<T> *newPtr) : nodePtr(newPtr)
        {}

        iterator operator=(node<T> *pNode)
        {
            this->nodePtr = pNode;
            return *this;
        }

        bool operator!=(const iterator &itr) const
        {
            return nodePtr != itr.nodePtr;
        }

        T operator*() const
        {
            if (nodePtr == NULL)
            {
                return 0;
            }
            return nodePtr->getValue();
        }

        iterator &operator++()
        {
            if (nodePtr == NULL)
            {
                return *this;
            }
            nodePtr = nodePtr->next;
            return *this;
        }

        iterator operator++(int)
        {
            if (nodePtr == NULL)
            {
                return *this;
            }
            iterator temp = *this;
            nodePtr = nodePtr->next;
            return temp;
        }
    };

    iterator begin() const
    {
        iterator it = iterator(root);
        return it;
    }

    iterator end() const
    {
        return iterator(NULL);
    }
};

template
class list<int>;

template
class list<char>;

template
class list<std::string>;

#endif // LIST_H
