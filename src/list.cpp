#include "list.h"

using namespace std;

template<typename T>
list<T>::list() :root(NULL) {}

template<typename T>
list<T>::list(const list<T>& l)
{
	node<T>* current = l.root;
	length = 0;
	root = NULL;
	while (current)
	{
		insert(current->getValue());
		current = current->next;
	}
}

template<typename T>
void list<T>::insert(const T& value)
{
	if (length == 0)
	{
		root = new node<T>(value);
	}
	else
	{
		root->append(value);
	}
	length++;
}

template<typename T>
bool list<T>::exists(const T& value) const
{
	if (length == 0)
	{
		return false;
	}
	else
	{
		return root->exists(value);
	}
}

template<typename T>
void list<T>::remove(const T& value)
{
	if (exists(value))
	{
		if (length == 0)
		{
			return;
		}
		node<T>* element = root;
		if (root->getValue() == value)
		{
			node<T>* temp = root->next;
			delete root;
			root = temp;
			length--;
			return;
		}
		for (unsigned int i = 0; i < length - 1; i++)
		{
			if (element->next->getValue() != value)
			{
				element = element->next;
				continue;
			}
			node<T>* temp = element->next->next;
			delete element->next;
			element->next = temp;
			length--;
			return;
		}
	}
}

template<typename T>
void list<T>::print() const
{
	if (length == 0)
	{
		return;
	}
	node<T>* current = root;
	while (current->next)
	{
		cout << current->getValue() << endl;
		current = current->next;
	}
	cout << current->getValue() << endl;
}

template<typename T>
int list<T>::getLength()
{
	return length;
}

template<typename T>
list<T>& list<T>::operator=(const list<T>& l)
{
	list<T> temp(l);
	std::swap(temp.root, root);
	length = l.length;
	return *this;
}

template<typename T>
list<T>::~list()
{
	if (length != 0)
	{
		node<T>* current = root;
		while (current)
		{
			node<T>* temp = current->next;
			delete current;
			current = temp;
		}
	}
}

template<typename T>
typename list<T>::iterator list<T>::begin()
{
	return list<T>::iterator(root);
}

template<typename T>
typename list<T>::iterator list<T>::end()
{
	return list<T>::iterator(NULL);
}

template<typename T>
typename list<T>::const_iterator list<T>::begin() const
{
	return list<T>::const_iterator(root);
}

template<typename T>
typename list<T>::const_iterator list<T>::end() const
{
	return list<T>::const_iterator(NULL);
}

template<typename T>
typename list<T>::const_iterator list<T>::cbegin() const
{
	return begin();
}

template<typename T>
typename list<T>::const_iterator list<T>::cend() const
{
	return end();
}