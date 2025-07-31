#include <iostream>
using namespace std;
using ll = long long;

template <typename type>
class list {
	size_t len = 0;
	type *array = nullptr;
public:
	list() : len(0) {};
	list(type *arr, size_t length);
	list(initializer_list<type> init);
	~list();

	list &operator=(const list &obj);
	list &operator=(initializer_list<type> init);
	list &operator+=(const list &obj);
	list operator+(const list &obj);
	type &operator[](size_t index) const;

	void expand(ll cnt);
	void copy(const list &obj);
	list read(size_t left, size_t right);
	void swap(size_t left, size_t right);
	void sort();
	void reverse();
	void remove(size_t index);
	void append(type elem);
	type &getelem(size_t index) const;
	const long long size() const;
	static list merge(const list &left, const list &right);
};
