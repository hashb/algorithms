#include <iostream>
#include <vector>


namespace skiena {
    int binary_search(std::vector<int> &arr, int low, int high, int key) {
        if (low > high) return -1;
        int mid = (low+high)/2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] > key) return binary_search(arr, low, mid-1, key);
        else return binary_search(arr, mid+1, high, key);
    }
} // skiena

int main() {
    std::vector<int> binary_search_arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int location = skiena::binary_search(binary_search_arr, 0, binary_search_arr.size()-1, 15);

    std::cout << "key was found at " << location << std::endl;

    return 0;
}