#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int split(vector<int> &array, int low, int high) {
    int pivot = array[low];

    while (true) {
        /// 1. find element higher than pivot & move it to left
        while (high > low && pivot <= array[high])
            high--;
        // if low & high meet, stop
        if (low >= high)
            break;
        // move it to left
        array[low++] = array[high];

        /// 2. find element lower than pivot from left & move it to right
        while (low < high && pivot >= array[low])
            low++;
        // if low & high meet, stop
        if (low >= high)
            break;
        // move it to right
        array[high--] = array[low];
    }
    /// 3. move the pivot to the position where low & high meet
    array[high] = pivot;

    return high;
}

void quicksort(vector<int> &array, int low, int high) {
    int middle;

    if (low >= high) return;

    /// 1. split array & return middle
    middle = split(array, low, high);
    /// 2. sort left part
    quicksort(array, low, middle - 1);
    /// 3. sort right part
    quicksort(array, middle + 1, high);
}

int main(int argc, char **argv) {
    vector<int> array {3, 4, 2, 1, 9, 8, 5, 6, 10, 7};

    quicksort(array, 0, array.size() - 1);
    for_each(array.begin(), array.end(), [] (int a) { cout << a << " "; });
    cout << endl;

    return 0;
}
