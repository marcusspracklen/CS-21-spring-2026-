#ifndef INTMINHEAP_H
#define INTMINHEAP_H

#include <string>
#include <utility>

class intMinHeap {
public:
	intMinHeap(int cap);
	~intMinHeap();

	std::pair<int *, int> heapsort();
	std::string toString();
	bool heapinsert(int val);
	int minimum();
	int extractmin();
	void decreasekey(int i, int k);
	int sizeOfHeap() {return size;}

	bool isEmpty() {return size == 0;}
	bool isFull() {return size == capacity;}

private:
	int minOf3(int i, int j, int k);
	int left(int i);
	int right(int i);
	int parent(int i);
	void buildheap();
	void heapify(int i);

	int *A;
	int capacity;
	int size;
};

#endif // INTMINHEAP_H
