#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> &left, vector<int> &right) {
    int i = 0, j = 0;
    vector<int> rst;

    /// 1. sort while merging left & right
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            rst.push_back(left[i]);
            i++;
        } else {
            rst.push_back(right[j]);
            j++;
        }
    }

    /// 2. merge remaining element
    if (i < left.size()) {
        for (int k = i; k < left.size(); k++) {
            rst.push_back(left[k]);
        }
    }
    if (j < right.size()) {
        for (int k = j; k < right.size(); k++) {
            rst.push_back(right[k]);
        }
    }

    return rst;
}

void merge_sort(vector<int> &array) {
    if (array.size() == 1) return;

    /// 1. split array into two parts: left & right
    vector<int> left(array.begin(), array.begin() + array.size() / 2);
    vector<int> right(array.begin() + array.size() / 2, array.end());
    
    /// 2. sort left part
    merge_sort(left);    
    /// 3. sort right part
    merge_sort(right);

    /// 4. merge left and right
    array = merge(left, right);
}

int main(int argc, char **argv) {
    vector<int> array {3, 4, 2, 1, 9, 8, 5, 6, 10, 7};
    merge_sort(array);

    for (auto a : array) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
