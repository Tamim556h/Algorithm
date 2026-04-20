#include <bits/stdc++.h>
using namespace std;

int rodCutting(int price[], int n) {
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int mx = INT_MIN;
        for (int j = 0; j < i; j++) {
            mx = max(mx, price[j] + dp[i - j - 1]);
        }
        dp[i] = mx;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    int price[n];
    for (int i = 0; i < n; i++)
        cin >> price[i];

    cout << rodCutting(price, n) << endl;

    return 0;
}
