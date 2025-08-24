#pragma once
#include <iostream>
using ll = long long;

template <typename type>
class list {
	size_t len = 0;
	type *array = nullptr;
public:
	list() : len(0) {};
	
	list(type elem) {
		expand(1);
		array[0] = elem;
	};

	list(type *arr, size_t length) {
		expand(length);
		for (size_t i = 0; i < len; i++)
			array[i] = arr[i];
	};
	
	list(std::initializer_list<type> init) {
		expand(init.size());
		for (size_t i = 0; i < len; i++)
		    array[i] = *(init.begin() + i);
	};

	list(const list &obj) {
		expand(obj.size());
		for (size_t i = 0; i < len; i++)
			array[i] = obj[i];
	};

	~list() {
		delete[] array;
	};
	

	list &operator=(const list &obj) {
		this->copy(obj);
		return *this;
	};

	list &operator=(std::initializer_list<type> init) {
		*this = list(init);
		return *this;
	};

	list &operator=(type elem) {
		*this = list(elem);
		return *this;
	};
	
	list &operator+=(const list &obj) {
		copy(merge(*this, obj));
		return *this;
	};

	list &operator+=(std::initializer_list<type> init) {
		*this += list(init);
		return *this;
	};

	list &operator+=(type elem) {
		*this += list(elem);
		return *this;
	};
	
	list operator+(const list &obj) {
		return merge(*this, obj);
	};

	list operator+(std::initializer_list<type> init) {
		return merge(*this, list(init));
	};

	list operator+(type elem) {
		return merge(*this, list(elem));
	};

	bool operator==(const list &obj) const {
		if (len != obj.len)
			return false;
		for (size_t i = 0; i < len; i++)
			if (array[i] != obj[i])
				return false;
		return true;
	};

	bool operator!=(const list &obj) const {
		return !(obj == *this);
	};

	bool operator>=(const list &obj) const {
		if (len >= obj.len)
			return true;
		return false;
	};

	bool operator<=(const list &obj) const {
		if (len <= obj.len)
			return true;
		return false;
	};

	bool operator>(const list &obj) const {
		if (len > obj.len)
			return true;
		return false;
	};

	bool operator<(const list &obj) const {
		if (len < obj.len)
			return true;
		return false;
	};

	type &operator[](size_t index) const {
		return array[index];
	};

	list operator()(size_t left = 0, size_t right = size(), ll step = 1) const {
		return list<type>(read(left, right, step));
	};

	friend std::ostream &operator<<(std::ostream &out, const list &obj) {
		out << '[' << obj[0];
		for (size_t i = 1; i < obj.size(); i++)
			out << ", " << obj[i];
		out << ']';
		return out;
	};


	void expand(ll cnt) {
		type *new_array = new type[len + cnt];
		if (cnt < 0)
			for (size_t i = 0; i < len + cnt; i++)	
				new_array[i] = array[i];
		else
			for (size_t i = 0; i < len; i++)	
				new_array[i] = array[i];
		delete[] array;
		array = new_array;
		len += cnt;
	};
	
	void copy(const list &obj) {
		len = obj.len;
		type *new_array = new type[len];
		for (size_t i = 0; i < len; i++) {
			new_array[i] = obj[i];
		}
		array = new_array;
	};
	
	list read(size_t left, size_t right, ll step = 1) const {
		list<type> new_list;
		new_list.expand(right - left);
		size_t j = 0;
		for (size_t i = left; i < right; i += step)
			new_list[j++] = array[i];
		new_list.expand(j - new_list.len);
		return new_list;
	};
	
	void swap(size_t left, size_t right) {
		type stdata = array[left];
		array[left] = array[right];
		array[right] = stdata;
	};
	
	void sort() {
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
	
	void reverse() {
		size_t left = 0, right = len - 1;
		while (left < right) {
			swap(left, right);
			left++;
			right--;
		}
	};

	bool find(type elem) const {
		for (size_t i = 0; i < len; i++)
			if (elem == array[i])
				return true;
		return false;
	};

	long long index(type elem) const {
		for (size_t i = 0; i < len; i++)
			if (elem == array[i])
				return i;
		return -1;
	};
	
	void pop_first() {
		copy(read(1, len));
	};
	
	void pop_back() {
		copy(read(0, len - 1));
	};
	
	void remove(size_t index, size_t amount = 1) {
		copy(read(0, index) + read(index + amount, len));
	};
	
	void append(type elem) {
		expand(1);
		array[len - 1] = elem;
	};
	
	void appbeg(type elem) {
		copy(list(elem) + read(0, len));
	};
	
	type &getelem(size_t index) const {
		return array[index];
	};
	
	const long long size() const {
		return len;
	};
	
	static list merge(const list &left, const list &right) {
		list<type> stdata;
		stdata.expand(left.len + right.len);
		for (size_t i = 0; i < left.len; i++)
			stdata[i] = left[i];
		size_t j = 0;
		for (size_t i = left.len; i < stdata.len; i++)
			stdata[i] = right[j++];
		return stdata;
	};
};
