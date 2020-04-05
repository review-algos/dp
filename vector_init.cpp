#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> vec) {
    for_each(vec.begin(), vec.end(), [] (int v) { cout << v << " "; });
    cout << endl;
}

void print(vector<vector<int>> vec2d) {
    for (auto it = vec2d.begin(); it != vec2d.end(); it++) {
        auto vec = *it;
        for_each(vec.begin(), vec.end(), [] (int v) { cout << v << " "; });
        cout << endl;
    }
}

int main(int argc, char **argv) {
    vector<int> vec {1, 2, 3, 4, 5, 6, 7};
    vector<int> vec2(7, 4);
    vector<vector<int>> vec3 {
        {0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 0}
    };

    vector<int> left(vec.begin(), vec.begin() + 2);

    cout << "vec: ";
    print(vec);
    cout << "vec2: ";
    print(vec2);
    print(vec3);
    return 0;
}
