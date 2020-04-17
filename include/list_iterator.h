#ifndef CONTAINER_LIST_ITERATOR_H
#define CONTAINER_LIST_ITERATOR_H

#include <iostream>
#include "node.h"
#include <iterator>

template<typename NodeT>
class list_iterator
{

 private:
	NodeT* node;

 public:
	using value_type = typename NodeT::value_type;
	using difference_type = typename NodeT::value_type;
	using size_type = std::size_t;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	typedef std::forward_iterator_tag iterator_category;

	list_iterator()
		: node(NULL)
	{
	}

	list_iterator(NodeT* newPtr)
		: node(newPtr)
	{
	}

	list_iterator operator=(NodeT* pNode);

	bool operator==(const list_iterator& itr) const;

	bool operator!=(const list_iterator& itr) const;

	list_iterator operator+(int i);

	value_type operator*() const;

	list_iterator operator++();

	list_iterator operator++(int);

};

template
class list_iterator<node<int>>;

template
class list_iterator<node<char>>;

template
class list_iterator<node<std::string>>;

#endif //CONTAINER_LIST_ITERATOR_H
