#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mfknapsack(int i, int j, vector<vector<int>> &F, vector<pair<int, int>> things) {
    if (F[i][j] < 0) {
        if (j >= things[i - 1].first)
            F[i][j] = max(mfknapsack(i - 1, j, F, things), mfknapsack(i - 1, j - things[i - 1].first, F, things) + things[i - 1].second);
        else
            F[i][j] = mfknapsack(i - 1, j, F, things);
    }
    return F[i][j];
}

int knapsack(vector<pair<int, int>> things, int capacity, vector<int> &result) {
    int n = things.size() + 1;
    int m = capacity + 1;
    vector<vector<int>> F(n, vector<int>(m, -1));
    
    for (int i = 0; i < n; i++)
        F[i][0] = 0;
    for (int j = 0; j < m; j++)
        F[0][j] = 0;

    int rst = mfknapsack(n - 1, m - 1, F, things);

    /// 2. backtrace result set
    for (int i = n - 1, j = m - 1; i != 0 && j != 0; i--) {
        if (F[i][j] != F[i - 1][j]) {
            result.push_back(i);
            j -= things[i - 1].first;
        }
    }

    return rst;
}

int main(int argc, char **argv) {
    // first: weight, second: value
    vector<pair<int, int>> things {pair<int, int>(2, 12), pair<int, int>(1, 10), pair<int, int>(3, 20), pair<int, int>(2, 15)};
    int weight = 5;

    vector<int> results;
    int rst = knapsack(things, weight, results);

    if (rst != -1) {
        cout << "The max value is: " << rst << endl;
        cout << "The result set is: ";
        for_each(results.begin(), results.end(), [](int a){ cout << a << " "; });
        cout << endl;
    }

    return 0;
}
