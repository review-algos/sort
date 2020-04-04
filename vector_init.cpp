#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> vec) {
    for_each(vec.begin(), vec.end(), [] (int v) { cout << v << " "; });
    cout << endl;
}

int main(int argc, char **argv) {
    vector<int> vec {1, 2, 3, 4, 5, 6, 7};
    vector<int> vec2(7, 4);

    vector<int> left(vec.begin(), vec.begin() + 2);

    cout << "vec: ";
    print(vec);
    cout << "vec2: ";
    print(vec2);
    return 0;
}
