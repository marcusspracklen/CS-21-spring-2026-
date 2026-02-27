#include <iostream>
#include "intMinHeap.h"

int main() {
	intMinHeap heap(2400000);

	int val;
	while (std::cin >> val) {
		if (val > 0) {
			heap.heapinsert(val);
			std::cout << "insert: " << val << "\n";
		} else if (val == 0) {
			std::cout << "heap size " << heap.sizeOfHeap() << ": " << heap.toString() << "\n";

		} else if (val == -1) {
			std::cout << "extract min: " << heap.extractmin() << "\n";

		} else if (val == -2) {
			auto [arr, sz] = heap.heapsort();
			std::cout << "sorted array: [";
			for (int i = 0; i < sz; i++) {
				std::cout << arr[i];
				if (i < sz -1) std::cout << ", ";
			}	
			std::cout << "]" << "\n";
			delete[] arr;
		}
	}

	return 0;
}
