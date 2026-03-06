#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <string>

const int M03_THRESHOLD = 25;

int medianOfThree(std::vector<int>& vec, int a, int b, int c);

// Lomuto Partition

int lomutoPartition(std::vector<int>& vec, int low, int high);

void quickSortLomuto(std::vector<int>& vec, int low, int high);

void sortLomuto(std::vector<int>& vec);

// Hoare Partition

int hoarePartition(std::vector<int>& vec, int low, int high);

void quickSortHoare(std::vector<int>& vec, int low, int high);

void sortHoare(std::vector<int>& vec);

#endif // QUICKSORT_H

