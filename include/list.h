#ifndef LIST_H
#define LIST_H

#include "Container.h"
#include "list_iterator.h"
#include <algorithm>

template<typename T>
class list : public Container<T>
{
 private:
	unsigned int length = 0;
	node<T>* root;

 public:
	typedef list_iterator<node<T>> iterator;
	typedef list_iterator<const node<T>> const_iterator;

	list();

	list(const list<T>& l);

	void insert(const T& value) override;

	bool exists(const T& value) const override;

	void remove(const T& value) override;

	void print() const;

	int getLength();

	list<T>& operator=(const list<T>& l);

	~list();

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	const_iterator cbegin() const;
	const_iterator cend() const;
	
};

template class list<int>;
template class list<std::string>;

#endif // LIST_H
