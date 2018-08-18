/** Implementing sorting algorithms from The Algorithm Design Manual
 * In this file we will be implementing:
 *   - Heap Sort
 *   - Merge Sort
 *   - Quick Sort
*/
#include "sorting.hpp"
#include <queue>

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

int main() {
    std::vector<int> test_arr = {9,8,7,6,5,4,3,2,1};

    for (int i:test_arr) std::cout << i << " ";
    std::cout << " size:" << test_arr.size() << std::endl;

    skiena::merge_sort(test_arr, 0, test_arr.size());

    for (int i:test_arr) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}