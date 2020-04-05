#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coin_row(vector<int> coins, vector<int> &selected) {
    if (coins.empty()) return -1;
    // store the largest value in every amount
    vector<int> values(coins.size() + 1, 0);
    vector<unsigned int> records;

    /// 1. init when amount is 0 & 1
    values[0] = 0;    values[1] = coins[0];
    for (unsigned int i = 2; i < values.size(); i++) { 
        int tmp = values[i - 2] + coins[i - 1]; 
        /// 2. compute max{F(n-1), F(n-2)+Cn}
        if (tmp > values[i - 1]) {
            values[i] = tmp;
            records.push_back(i - 2);
        } else {
            values[i] = values[i - 1];
            records.push_back(i - 1);
        }
    }

    /// 3. backtrace to get the value selected
    unsigned int prev = values.size() - 1;
    unsigned rid = prev - 2;
    while (prev > 1) {
        if (records[rid] == (prev - 2)) {
            selected.push_back(values[prev] - values[records[rid]]);
        } 
        prev = records[rid];
        if (prev == 1) {
            selected.push_back(values[1]); 
        }
        rid = prev - 2;
    }

    return values[values.size() - 1];
}

int main(int argc, char **argv) {
    vector<int> coins {5, 1, 2, 10, 6, 2};
    vector<int> results;

    int rst = coin_row(coins, results);
    
    if (rst != -1) {
        cout << "The max value is: " << rst << endl;
        cout << "The coins selected are: ";
        for (int i = results.size() - 1; i >= 0; i--)
            cout << results[i] << " ";
        cout << endl;
    } else {
        cout << "Cannot find the max value!" << endl;
    }

    return 0;
}
