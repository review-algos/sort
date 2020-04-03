#include <iostream>
#include <vector>

using namespace std;

int split(vector<int> &array, int low, int high) {
    int pivot = array[low];

    while (true) {
        while (high > low && pivot <= array[high])
            high--;
        if (low >= high)
            break;
        array[low++] = array[high];

        while (low < high && pivot >= array[low])
            low++;
        if (low >= high)
            break;
        array[high--] = array[low];
    }
    array[high] = pivot;

    return high;
}

void quicksort(vector<int> &array, int low, int high) {
    int middle;

    if (low >= high) return;

    middle = split(array, low, high);
    quicksort(array, low, middle - 1);
    quicksort(array, middle + 1, high);
}

int main(int argc, char **argv) {
    vector<int> array {3, 4, 2, 1, 9, 8, 5, 6, 10, 7};

    quicksort(array, 0, array.size() - 1);
    for_each(array.begin(), array.end(), [] (int a) { cout << a << " "; });
    cout << endl;

    return 0;
}
