#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b) {
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(vector<int> &array) {
    /// 1. traverse array 
    for (int i = 0; i < array.size(); i++) {
        /// 2. move the biggest bubble to 'top'
        for (int j = 0; j < array.size() - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int main(int argc, char** argv) {
    vector<int> array {3, 4, 2, 1, 9, 8, 5, 6, 10, 7};
    
    bubble_sort(array);

    for (auto a: array) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
