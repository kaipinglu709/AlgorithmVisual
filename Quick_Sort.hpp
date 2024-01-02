// QuickSort.hpp

#pragma once
#include <vector>

class QuickSort {
public:
    static void sort(std::vector<int>& arr) {
        quickSort(arr, 0, arr.size() - 1);
    }

private:
    static void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);  // Before pivot
            quickSort(arr, pivotIndex + 1, high); // After pivot
        }
    }

    static int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
};
