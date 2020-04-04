#include <iostream>
#include <vector>

using namespace std;

void select_sort(vector<int> &array) {
    /// 1. traverse array
    for (unsigned int i = 0; i < array.size() - 1; i++) {
        unsigned int min_idx = i;
        /// 2. find the min element
        for (unsigned int j = i + 1; j < array.size(); j++) {
            if (array[min_idx] > array[j]) {
               min_idx = j; 
            } 
        }
        /// 3. move it to front
        int tmp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = tmp;
    }
}

int main(int argc, char **argv) {
    vector<int> array{3, 4, 2, 1, 9, 8, 5, 6, 10, 7};

    select_sort(array);

    for (auto it = array.begin(); it != array.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
