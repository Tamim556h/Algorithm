#include <bits/stdc++.h>  // Tamim -BSSE-1650
using namespace std;

int keyIndex(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c == '*') return 10;
    return 11; 
}

vector<pair<int,int>> coord = {
    {3,1}, // 0
    {0,0}, {0,1}, {0,2}, //1 2 3
    {1,0}, {1,1}, {1,2}, // 4 5 6
    {2,0}, {2,1}, {2,2}, //7 8 9
    {3,0}, // *
    {3,2}  // #
};

double dist(int a, int b) {
    int dx = coord[a].first - coord[b].first;
    int dy = coord[a].second - coord[b].second;
    double d = sqrt(dx * dx + dy * dy);
    return round(d * 2) / 2.0;
}

int main() {

    string number;
    cout<<"Enter your Number: ";
    cin >> number;
    int n = number.size();

    vector<vector<vector<double>>> dp(
        n + 1, vector<vector<double>>(12, vector<double>(12, 1e18))
    );

    for (int x = 0; x < 12; x++)
        for (int y = 0; y < 12; y++)
            dp[n][x][y] = 0;


    for (int i = n - 1; i >= 0; i--) {
        int digit = keyIndex(number[i]);
        for (int x = 0; x < 12; x++) {
            for (int y = 0; y < 12; y++) {

                double costA = dist(x, digit) + dp[i + 1][digit][y];

                double costB = dist(y, digit) + dp[i + 1][x][digit];

                dp[i][x][y] = min(costA, costB);
            }
        }
    }

    // Initial positions: A on '*', B on '#'
    cout << fixed << setprecision(1)<<"Least Amount: "
         << dp[0][10][11] << endl;

    return 0;
}
