#include <iostream>
#include "geralist.h"
using namespace std;
using ll = long long;

template <class type>
list<type>::list(type *arr, size_t length) {
	expand(length);
	for (size_t i = 0; i < len; i++)
		array[i] = arr[i];
};

template <class type>
list<type>::list(initializer_list<type> init) {
	expand(init.size());
    for (size_t i = 0; i < len; i++)
        array[i] = *(init.begin() + i);
};

template <class type>
list<type>::~list() {
	delete[] array;
};

template <class type>
list<type> &list<type>::operator=(const list &obj) {
	this->copy(obj);
	return *this;
};

template <class type>
list<type> &list<type>::operator=(initializer_list<type> init) {
	this = list(init);
	return *this;
};

template <class type>
list<type> &list<type>::operator+=(const list &obj) {
	copy(merge(*this, obj));
	return *this;
};

template <class type>
list<type> list<type>::operator+(const list &obj) {
	return merge(*this, obj);
};

template <class type>
type &list<type>::operator[](size_t index) const {
	return array[index];
};

template <class type>
void list<type>::expand(ll cnt) {
	type *new_array = new type[len + cnt];
	if (cnt < 0)
		for (size_t i = 0; i < len + cnt; i++)	
			new_array[i] = array[i];
	else
		for (size_t i = 0; i < len; i++)	
			new_array[i] = array[i];
	array = new_array;
	len += cnt;
};

template <class type>
void list<type>::copy(const list &obj) {
	len = obj.len;
	type *new_array = new type[len];
	for (size_t i = 0; i < len; i++) {
		new_array[i] = obj[i];
	}
	array = new_array;
};

template <class type>
list<type> list<type>::read(size_t left, size_t right) {
	list<type> new_list;
	new_list.expand(right - left);
	size_t j = 0;
	for (size_t i = left; i < right; i++)
		new_list[j++] = array[i];
	return new_list;
};

template <class type>
void list<type>::swap(size_t left, size_t right) {
	type stdata = array[left];
	array[left] = array[right];
	array[right] = stdata;
};

template <class type>
void list<type>::sort() {
	bool sorted;
	for (size_t k = 1; k < len; k++) {
		sorted = true;
		for (size_t it = 0; it < len - k; it++) {
			if (array[it] > array[it + 1]) {
				swap(it, it + 1);
				sorted = false;
			}
		}
		if (sorted)
			break;
	}
};

template <class type>
void list<type>::reverse() {
	size_t left = 0, right = len - 1;
	while (left < right) {
		swap(left, right);
		left++;
		right--;
	}
};

template <class type>
void list<type>::remove(size_t index) {
	copy(read(0, index) + read(index + 1, len));
};

template <class type>
void list<type>::append(type elem) {
	expand(1);
	array[len - 1] = elem;
};

template <class type>
type &list<type>::getelem(size_t index) const {
	return array[index];
};

template <class type>
const long long list<type>::size() const {
	return len;
};

template <class type>
list<type> list<type>::merge(const list &left, const list &right) {
	list<type> stdata;
	stdata.expand(left.len + right.len);
	for (size_t i = 0; i < left.len; i++)
		stdata[i] = left[i];
	size_t j = 0;
	for (size_t i = left.len; i < stdata.len; i++)
		stdata[i] = right[j++];
	return stdata;
};
