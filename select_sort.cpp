#include <iostream>
#include <vector>

using namespace std;

void select_sort(vector<int> &array) {
    for (int i = 0; i < array.size() - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[min_idx] > array[j]) {
               min_idx = j; 
            } 
        }
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
