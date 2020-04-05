#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coin_change(vector<unsigned int> coins, unsigned int n) {
    if (coins.empty() || n < 1) return -1;

    vector<int> F(n, 0); // F(0) = 0

    /// 1. Compute F(n) from 1 to n: F(n)=min{F(n-C[n])}+1
    for (unsigned int i = 1; i < n; i++) {
        int temp = 0;
        if (i >= coins[0]) temp = F[i - coins[0]] + 1;
        else break;

        /// get the min count
        for (unsigned int j = 1; j < coins.size(); j++) {
            if (i > coins[j]) {
                temp = min(F[i - coins[j]] + 1, temp);
            }
        }
        F[i] = temp;
    }

    return F[n - 1];
}

int main(int argc, char **argv) {
    vector<unsigned int> coins {1, 3, 4};
    int n = 6;

    sort(coins.begin(), coins.end(), less<int>());
    int rst = coin_change(coins, n);

    if (rst != -1)
        cout << "The min count is: " << rst << endl;
    else
        cout << "Cannot find the max value!" << endl;

    return 0;
}
