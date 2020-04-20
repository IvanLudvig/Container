#include "list_iterator.h"

template<typename NodeT>
list_iterator<NodeT>::list_iterator(NodeT* node) : node(node) {}

template<typename NodeT>
list_iterator<NodeT> list_iterator<NodeT>::operator=(NodeT* node)
{
	this->node = node;
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
	if (node)
	{
		return node->getValue();;
	}
	return 0;
}

template<typename NodeT>
list_iterator<NodeT> list_iterator<NodeT>::operator++()
{
	if (node)
	{
		node = node->next;
	}
	return *this;
}

template<typename NodeT>
list_iterator<NodeT> list_iterator<NodeT>::operator++(int)
{
	if (node)
	{
		list_iterator temp = *this;
		node = node->next;
		return temp;

	}
	return *this;

}