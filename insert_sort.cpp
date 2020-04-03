#include <iostream>
#include <vector>

using namespace std;

void insert_sort(vector<int> &array) {
    vector<int> rst;

    rst.push_back(array[0]);

    for (int i = 1; i < array.size(); i++) {
        if (rst[rst.size() - 1] < array[i]) {
            rst.push_back(array[i]);
            continue;
        } else {
            int pos = rst.size() - 1;
            for (int j = 0; j < rst.size(); j++) {
                if (rst[rst.size() - j - 1] > array[i]) {
                    pos = rst.size() - j - 1;
                } else 
                    break;
            }
            rst.insert(rst.begin() + pos, array[i]);
        }
    }

    array = rst;
}

int main(int argc, char **argv) {
    vector<int> array{3, 4, 2, 1, 9, 8, 5, 6, 10, 7};

    insert_sort(array);
    for_each(array.begin(), array.end(), [] (int r) { cout << r << " "; });
    cout << endl;

    return 0;
}
