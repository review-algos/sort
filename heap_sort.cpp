#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &array, int n, int i) {
    int l = i * 2 + 1; // left child
    int r = i * 2 + 2; // right child
    int largest = i;

    /// 1. adjust left child
    if (l < n && array[l] > array[largest])
        largest = l;
    /// 2. adjust right child
    if (r < n && array[r] > array[largest])
        largest = r;

    /// 3. swap & re-heapify down
    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}

void heap_sort(vector<int> &array) {
    int len = array.size();
    /// 1. build heap
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(array, array.size(), i);

    /// 2. re-build heap for remaining array except last item
    for (int i = len - 1; i > 0; i--) {
        swap(array[i], array[0]);
        heapify(array, i, 0);
    }
}

int main(int argc, char** argv) {
    vector<int> array {3, 4, 2, 1, 9, 8, 5, 6, 10, 7};
    
    heap_sort(array);
    for (auto a: array) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
