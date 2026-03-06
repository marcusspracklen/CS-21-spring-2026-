#include "quickSort.h"
#include <vector>
#include <algorithm>

// Returns index (between a, b, and c) whose value is the median of the three
int medianOfThree(std::vector<int>& vec, int a, int b, int c) {
	int va = vec[a], vb = vec[b], vc = vec[c];

	if ((va <= vb && vb <= vc) || (vc <= vb && vb <= va)) return b;
	if ((vb <= va && va <= vc) || (vc <= va && va <= vb)) return a;
	return c;
}


// Lomuto Implementation


int lomutoPartition(std::vector<int>& vec, int low, int high) {
	if ((high - low + 1) >= M03_THRESHOLD) {
		int mid = low + (high - low) / 2;
		int pivotIndex = medianOfThree(vec, low, mid, high);
		std::swap(vec[pivotIndex], vec[high]);
	}
	
	int x = vec[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (vec[j] <= x) {
			std::swap(vec[i], vec[j]);
			i++;
		}
	}
	std::swap(vec[i + 1], vec[high]);
	return i + 1;
}

void quickSortLomuto(std::vector<int>& vec, int low, int high) {
	if (low < high) {
		int q = lomutoPartition(vec, low, high);
		quickSortLomuto(vec, low, q-1);
		quickSortLomuto(vec, q+1, high);	
	}
}


// Hoare Implementation


int hoarePartition(std::vector<int>& vec, int low, int high) {
	if ((high - low + 1) >= M03_THRESHOLD) {
		int mid = low + (high - low) / 2;
		int pivotIndex = medianOfThree(vec, low, mid, high);
		std::swap(vec[pivotIndex], vec[low]);
	}
	
	int x = vec[low]; // pivot
	int i = low - 1;
	int j = high + 1;

	while (true) {

		do { i = i + 1; } while (vec[i] < x);

		do { j = j - 1; } while (vec[j] > x);

		if (i >= j) return j;

		std::swap(vec[i], vec[j]);
	}
}

void quickSortHoare(std::vector<int>& vec, int low, int high) {
	if (low < high) {
		int q = hoarePartition(vec, low, high);
		quickSortHoare(vec, low, q);
		quickSortHoare(vec, q + 1, high);
	}
}

// Quality of life function for Lomuto allowing user to just call a sort and hand over a vector
void sortLomuto(std::vector<int>& vec) {
	if (vec.size() > 1) {
		quickSortLomuto(vec, 0, (int)vec.size() -1);
	}
}

// Quality of life function for Hoare allowing user to just call a sort and hand over a vector
void sortHoare(std::vector<int>& vec) {
	if (vec.size() > 1) {
		quickSortHoare(vec, 0, (int)vec.size() - 1);
	}
}
