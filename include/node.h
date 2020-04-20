#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

template<typename T>
class node
{
 private:
	T value;
 public:
	typedef T value_type;

	node<T>(const T& data = 0);

	void append(const T& data);

	bool exists(const T& data);

	node<T>* getNext() const;

	T getValue() const;

	node<T>* next;

	~node();
};

template class node<int>;
template class node<std::string>;

#endif // NODE_H
