#include <vector>
#include <iostream>

namespace skiena {
    void heap_sort(std::vector<int> &arr);

    void merge(std::vector<int> &arr, int low, int mid, int high);
    void merge_sort(std::vector<int> &arr, int low, int high); 

    int partition(std::vector<int> &arr, int low, int high);
    void quick_sort(std::vector<int> &arr, int low, int high);
}