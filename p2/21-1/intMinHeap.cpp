#include "intMinHeap.h"
#include <sstream>
#include <string>

intMinHeap::intMinHeap(int cap) : capacity(cap), size(0) {
	A = new int[capacity];
}

intMinHeap::~intMinHeap() {
	delete[] A;
}


// Private Helper functions
int intMinHeap::left(int i) {
	return 2 * i + 1;
}

int intMinHeap::right(int i) {
	return 2 * i + 2;
}

int intMinHeap::parent(int i) {
	return (i - 1) / 2;
}
int intMinHeap::minOf3(int i, int j, int k) {
	int m = i;
	if (j < size && A[j] < A[m]) m = j;
	if (k < size && A[k] < A[m]) m = k;
	return m;
}


void intMinHeap::heapify(int i) {
	int n = minOf3(i, left(i), right(i));
	if (n != i) {
		std::swap(A[i], A[n]);
		heapify(n);
	}
}

void intMinHeap::buildheap() {
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(i);
	}
}

// Public functions
bool intMinHeap::heapinsert(int val) {
	if (isFull()) return false;

	A[size] = val + 1;
	size++;
	decreasekey(size - 1, val);
	return true;
}

int intMinHeap::minimum() {
	if (isEmpty()) return 0;
	return A[0];
}

int intMinHeap::extractmin() {
	if (isEmpty()) return 0;
	int min = A[0];
	A[0] = A[size-1];
	size--;
	heapify(0);
	return min;
}

void intMinHeap::decreasekey(int i, int k) {
	if (i < 0 || i >= size) return;
	if (k > A[i]) return; 
	A[i] = k;

	while (i > 0 && A[parent(i)] > A[i]) {
		std::swap(A[i], A[parent(i)]);
		i = parent(i);
	}
}

std::pair<int*, int> intMinHeap::heapsort() {
	int n = size;
	
	// Save current heap
	int* backup = new int[n];
	for (int i = 0; i < n; i++) backup[i] = A[i];

	int* result = new int[n];
	for (int i = n - 1; i >= 0; i--) {
		std::swap(A[0], A[i]);
		size--;
		heapify(0);
	}

	// copy resultant array
	for (int i = 0; i < n; i++) {
		result[i] = A[i];
	}

	// restore heap
	size = n;
	for (int i = 0; i < n; i++) A[i] = backup[i];
	delete[] backup;

	return std::make_pair(result, n);
}

std::string intMinHeap::toString() {
	std::ostringstream oss;
	for (int i = 0; i < size; i++) {
		oss << A[i];
		if (i < size - 1) oss << ", ";
	}
	return oss.str();
}
