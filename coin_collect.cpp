#include <iostream>
#include <vector>

using namespace std;

int coin_collect(vector<vector<int>> board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> F(n, vector<int>(m, 0));

    for (int j = 1; j < m; j++) {
        F[0][j] = F[0][j - 1] + board[0][j];
    }

    for (int i = 1; i < n; i++) {
        F[i][0] = F[i - 1][0] + board[i][0];
        for (int j = 1; j < m; j++) {
            F[i][j] = max(F[i][j - 1], F[i - 1][j]) + board[i][j]; 
        }
    }

    return F[n - 1][m - 1];
}

int main(int argc, char **argv) {
    vector<vector<int>> input {
        {0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 0}
    };

    int rst = coin_collect(input);
     
    cout << "The max value is: " << rst << endl;

    return 0;
}
