#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &array) {
    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < array.size() - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
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
