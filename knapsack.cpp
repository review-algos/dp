#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(vector<pair<int, int>> things, int capacity, vector<int> &result) {
    int n = things.size() + 1;
    int m = capacity + 1;
    vector<vector<int>> F(n, vector<int>(m, 0));

    /// 1. compute F[i][j]
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            // if j > Wi then F[i][j]=max(F[i-1][j], F[i-1][j-Wi]+Vi)
            if (j >= things[i - 1].first) {
                F[i][j] = max(F[i - 1][j], F[i - 1][j - things[i - 1].first] + things[i - 1].second);
            // else F[i][j]=F[i-1][j]
            } else {
                F[i][j] = F[i - 1][j];
            }
        }
    }

    /// 2. backtrace result set
    for (int i = n - 1, j = m - 1; i != 0 && j != 0; i--) {
        if (F[i][j] != F[i - 1][j]) {
            result.push_back(i);
            j -= things[i - 1].first;
        }
    }
    
    return F[n - 1][m - 1];
}

int main(int argc, char **argv) {
    // first: weight, second: value
    vector<pair<int, int>> things {pair<int, int>(2, 12), pair<int, int>(1, 10), pair<int, int>(3, 20), pair<int, int>(2, 15)};
    int weight = 5;

    vector<int> results;
    int rst = knapsack(things, weight, results);

    if (rst != -1) {
        cout << "The max value is: " << rst << endl;
        for_each(results.begin(), results.end(), [](int a){ cout << a << " "; });
        cout << endl;
    }

    return 0;
}
