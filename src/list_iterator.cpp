#include "list_iterator.h"

template<typename NodeT>
list_iterator<NodeT> list_iterator<NodeT>::operator=(NodeT* pNode)
{
	this->node = pNode;
	return *this;
}

template<typename NodeT>
bool list_iterator<NodeT>::operator==(const list_iterator<NodeT>& itr) const
{
	return node == itr.node;
}

template<typename NodeT>
bool list_iterator<NodeT>::operator!=(const list_iterator& itr) const
{
	return node != itr.node;
}

template<typename NodeT>
list_iterator<NodeT> list_iterator<NodeT>::operator+(int i)
{
	list_iterator<NodeT> iter = *this;
	while ((i-- > 0) && (iter.node))
	{
		++iter;
	}
	return iter;
}

template<typename NodeT>
typename list_iterator<NodeT>::value_type list_iterator<NodeT>::operator*() const
{
	if (node == NULL)
	{
		return 0;
	}
	return node->getValue();
}

template<typename NodeT>
list_iterator<NodeT> list_iterator<NodeT>::operator++()
{
	if (node == NULL)
	{
		return *this;
	}
	node = node->next;
	return *this;
}

template<typename NodeT>
list_iterator<NodeT> list_iterator<NodeT>::operator++(int)
{
	if (node == NULL)
	{
		return *this;
	}
	list_iterator temp = *this;
	node = node->next;
	return temp;
}


