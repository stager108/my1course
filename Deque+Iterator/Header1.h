
#include <iostream>
#include <new>
#include <algorithm>
#include <ctime>
template <typename T> class Deque;

template <typename ItType>
class MyIterator : public std::iterator < std::random_access_iterator_tag, ItType> {

private:
	ItType *arr;
	size_t tail;
	size_t head;
	size_t element;
	size_t dsize;
	int position;
	int size_el;
public:
	MyIterator() {}
	~MyIterator() {}

	MyIterator(ItType* arr1, size_t head1, size_t tail1, size_t size_arr, size_t start) {
		element = start;
		head = head1;
		arr = arr1;
		dsize = size_arr;
		tail = tail1;
		position = start - head1;
		if (position < 0) position += size_arr;

		size_el = tail - head;
		if (size_el <= 0) size_el = size_el + dsize;

	}

	MyIterator(const MyIterator& W) {
		arr = W.arr;
		tail = W.tail;
		head = W.head;
		element = W.element;
		dsize = W.dsize;
		position = W.position;
		size_el = W.size_el;
	}

	bool operator == (const MyIterator &it) const {
		return (position == it.position);
	}
	bool operator != (const MyIterator &first) const {
		return (position != first.position);
	}

	ptrdiff_t  operator - (const MyIterator &it) const {
		return (position - it.position);
	}

	ItType& operator*() const {
		ItType* value;
		value = arr + element;
		return *value;
	}
	MyIterator operator--() {
		if (position > 0) {
			position--;
			element = (position + head) % dsize;
		}
		return *this;
	}
	MyIterator operator--(int) {
		if (position > 0) {
			position--;
			element = (position + head) % dsize;
		}
		return *this;
	}

	MyIterator& operator ++ () {
		if (size_el > position) {
			position++;
			element = (position + head) % dsize;
		}
		return *this;

	}
	MyIterator& operator ++ (int) {
		if (size_el > position) {
			position++;
			element = (position + head) % dsize;
		}
		return *this;

	}

	MyIterator& operator + (int k) {
		if (size_el >= position + k) {
			position += k;
			element = (position + head) % dsize;
		}
		return *this;

	}

	MyIterator& operator - (int k) {
		if (0 <= position - k) {
			position -= k;
			element = (position + head) % dsize;
		}
		return *this;
	}

	MyIterator& operator += (int k) {
		if (size_el >= position + k) {
			position += k;
			element = (position + head) % dsize;
		}
		return *this;

	}

	MyIterator& operator -= (int k) {
		if (position - k > -1) {
			position -= k;
			element = (position + head) % dsize;
		}
		return *this;
	}

	bool operator < (const MyIterator &it) {
		return (position < it.position);
	}

	bool operator > (const MyIterator &it) {
		return (position > it.position);
	}

	bool operator <= (const MyIterator &it) {
		return ((position <= it.position));
	}

	bool operator >= (const MyIterator &it) {
		return ((position >= it.position));
	}

	MyIterator operator = (const MyIterator &W) {
		arr = W.arr;
		tail = W.tail;
		head = W.head;
		element = W.element;
		dsize = W.dsize;
		position = W.position;
		size_el = W.size_el;
		return *this;
	}
};
template <typename T>
class Deque {
private:
	void check() {
		for (int i = 0; i < dsize; i++)
			std::cout << elem[i] << " ";
		std::cout << std::endl;
	}

	void resize(int newsize) {
		T *new_elem = new T[newsize];
		int s = size();
		for (int i = 0; i < s; i++) {
			new_elem[i] = elem[(head + i) % dsize];
		}
		head = 0;
		tail = s;
		dsize = newsize;
		T *c;
		c = elem;
		elem = new_elem;
		new_elem = c;
		delete[] new_elem;

	}
	int head;
	int k;
	int tail;
	size_t dsize;
	T *elem;
public:
	
	typedef MyIterator <T> iterator;
	typedef MyIterator <const T> const_iterator;
	typedef std::reverse_iterator <iterator> reverse_iterator;
	typedef std::reverse_iterator <const_iterator> const_reverse_iterator;

	Deque() {//empty deque
		head = 0;
		tail = 0;
		k = 0;
		elem = new T[4];
		dsize = 4;
		//cheque();
	}

	Deque(const Deque &other) {//copy other deque
		dsize = other.dsize;
		elem = new T[dsize];
		head = other.head;
		tail = other.tail;
		for (int i = 0; i < dsize; i++)
			elem[i] = other.elem[i];
		//check();
	}

	Deque(Deque &&other) {//move constructor
		elem = other.elem;
		head = other.head;
		tail = other.tail;
		dsize = other.dsize;
	}

	void push_back(T value) {
		if (size() + 1 == dsize) resize(2 * dsize);
		elem[tail] = value;
		tail++;
		if (tail == dsize) tail = 0;
		//check();
	}

	void push_front(T value) {
		if (size() + 1 == dsize) resize(2 * dsize);
		head--;
		if (head < 0) head = dsize - 1;
		elem[head] = value;
		//check();
	}

	void pop_back() {
		if (!empty()) {
			if (size() <= dsize / 4) resize(dsize / 2);
			tail--;
			if (tail < 0) tail = dsize - 1;
			//check();
		}
	}

	void pop_front() {
		if (!empty()) {
			if (size() <= dsize / 4) resize(dsize / 2);
			head++;
			if (head == dsize) head = 0;
		}
		//check();
	}



	T back() {//last element
		int e = (tail == 0) ? size() - 1 : tail - 1;
		return elem[e];
	}

	T back() const {
		int e = (tail == 0) ? size() - 1 : tail - 1;
		return elem[e];
	}

	T front() {//first element
		return elem[head];
	}

	T front() const {
		return elem[head];
	}

	T operator [] (int k) {
		k = k % size();
		int r = (head + k) % dsize;
		return elem[r];
	}

	T operator [] (int k) const {
		k = k % size();
		int r = (head + k) % dsize;
		return elem[r];
	}

	Deque<T> operator = (const Deque &other){
		
		head = other.head;
		k = other.k;
		tail = other.tail;
		dsize = other.dsize;
		T* arr = new T[dsize];
		for (int i = 0; i < dsize; i++) {
			arr[i] = other.elem[i];
		}
		T* c = elem;
		elem = arr;
		arr = c;
		delete [] arr;
		return *this;
	}

	bool empty() const {
		return (head == tail);
	}

	size_t size() const {//deque size
		int w = tail - head;
		if (w < 0) w = w + dsize;
		return w;
	}

	MyIterator<T> begin() {
		MyIterator<T> W(elem, head, tail, dsize, head);

		return W;
	}

	MyIterator <T> begin() const {
		iterator const W(elem, head, tail, dsize, head);
		return W;
	}

	const_iterator cbegin() const {
		const_iterator W(elem, head, tail, dsize, head);
		return W;
	}
	const_iterator cbegin() {
		const_iterator W(elem, head, tail, dsize, head);
		return W;
	}

	MyIterator <T> end() {
		iterator  W(elem, head, tail, dsize, tail);
		return W;
	}

	const_iterator  end() const {
		const_iterator W(elem, head, tail, dsize, tail);
		return W;
	}
	const_iterator cend() {
		const_iterator W(elem, head, tail, dsize, tail);
		return W;
	}
	const_iterator cend() const {
		const_iterator W(elem, head, tail, dsize, tail);
		return W;
	}

	reverse_iterator  rbegin() {
		return reverse_iterator(iterator(elem, head, tail, dsize, tail));

	}

	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(iterator(elem, head, tail, dsize, tail));
	}

	reverse_iterator rend() {
		return reverse_iterator(iterator(elem, head, tail, dsize, head));
	}

	const_reverse_iterator rend() const {
		return const_reverse_iterator(iterator(elem, head, tail, dsize, head));
	}

	~Deque() {
		delete[] elem;
	}
};
