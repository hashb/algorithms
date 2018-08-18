/** Implementing sorting algorithms from The Algorithm Design Manual
 * In this file we will be implementing:
 *   - Heap Sort
 *   - Merge Sort
 *   - Quick Sort
*/
#include "sorting.hpp"
#include <queue>
#include <algorithm>

/* Heap Sort */
void skiena::heap_sort(std::vector<int> &arr) {
    std::priority_queue<int, 
                        std::vector<int>, 
                        std::greater<int>> q;
    
    for (int i:arr) q.push(i);

    int i = 0;
    while (!q.empty()) {
        arr[i] = q.top();
        q.pop();
        i++;
    }
}

/* Merge Sort */

void skiena::merge(std::vector<int> &arr, int low, int mid, int high) {
    std::queue<int> buffer1, buffer2;

    for (int i=low; i<=mid; i++) buffer1.push(arr[i]);
    for (int i=mid+1; i<=high; i++) buffer2.push(arr[i]);

    int i = low;
    while (buffer1.size()>0 && buffer2.size()>0) {
        if (buffer1.front() <= buffer2.front()) {
            arr[i++] = buffer1.front();
            buffer1.pop();
        }
        else {
            arr[i++] = buffer2.front();
            buffer2.pop();
        }
    }

    while (buffer1.size()>0) {
        arr[i++] = buffer1.front();
        buffer1.pop();
    }

    while (buffer2.size()>0) {
        arr[i++] = buffer2.front();
        buffer2.pop();
    }
}

void skiena::merge_sort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int mid = (low+high)/2;
        skiena::merge_sort(arr, low, mid);
        skiena::merge_sort(arr, mid+1, high);
        skiena::merge(arr, low, mid, high);
    }
}

/* Quick Sort */

int skiena::partition(std::vector<int> &arr, int low, int high) {
    int part = high;
    int pivot = arr[part];

    int first_high = low;

    for (int i=low; i<high; i++) {
        if (arr[i] < pivot) {
            std::swap(arr[i], arr[first_high]);
            first_high++;
        }
    }

    std::swap(arr[part], arr[first_high]);
    return first_high;
}

void skiena::quick_sort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int p = skiena::partition(arr, low, high);
        quick_sort(arr, low, p-1);
        quick_sort(arr, p+1, high);
    }
}

int main() {
    // Heap Sort
    std::vector<int> heap_sort_arr = {9,8,7,6,5,4,3,2,1};

    std::cout << "heap Sort: \n";
    for (int i:heap_sort_arr) std::cout << i << " ";
    std::cout << " size:" << heap_sort_arr.size() << std::endl;

    skiena::heap_sort(heap_sort_arr);

    for (int i:heap_sort_arr) std::cout << i << " ";
    std::cout << std::endl;

    // Merge Sort
    std::vector<int> merge_sort_arr = {9,8,7,6,5,4,3,2,1};

    std::cout << "Merge Sort: \n";
    for (int i:merge_sort_arr) std::cout << i << " ";
    std::cout << " size:" << merge_sort_arr.size() << std::endl;

    skiena::merge_sort(merge_sort_arr, 0, merge_sort_arr.size()-1);

    for (int i:merge_sort_arr) std::cout << i << " ";
    std::cout << std::endl;

    // Quicksort
    std::vector<int> quick_sort_arr = {9,8,7,6,5,4,3,2,1};

    std::cout << "Quick Sort: \n";
    for (int i:quick_sort_arr) std::cout << i << " ";
    std::cout << " size:" << quick_sort_arr.size() << std::endl;

    skiena::quick_sort(quick_sort_arr, 0, quick_sort_arr.size()-1);

    for (int i:quick_sort_arr) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}