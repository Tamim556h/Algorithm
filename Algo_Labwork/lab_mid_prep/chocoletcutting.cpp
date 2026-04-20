#include <bits/stdc++.h>
using namespace std;

int main() {
    int M = 4, N = 10;

    int p[5][11] = {
        {0},
        {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30},
        {0, 5, 6, 18, 22, 31, 35, 37, 39, 40, 45},
        {0, 8, 18, 22, 34, 37, 39, 42, 43, 45, 48},
        {0, 9, 22, 34, 40, 44, 47, 48, 50, 52, 53}
    };

    int r[5][11];

    // DP computation
    for (int m = 1; m <= M; m++) {
        for (int n = 1; n <= N; n++) {
            r[m][n] = p[m][n]; // sell without cutting

            // Vertical cuts
            for (int i = 1; i < m; i++) {
                r[m][n] = max(r[m][n], r[i][n] + r[m - i][n]);
            }

            // Horizontal cuts
            for (int j = 1; j < n; j++) {
                r[m][n] = max(r[m][n], r[m][j] + r[m][n - j]);
            }
        }
    }

    cout << "Maximum revenue for " << M << " x " << N
         << " chocolate = " << r[M][N] << endl;

    return 0;
}
