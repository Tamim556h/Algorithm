#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int dp[n];

    // Initialize dp with array values
    for (int i = 0; i < n; i++)
        dp[i] = arr[i];

    // DP computation
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    int ans = *max_element(dp, dp + n);
    cout << ans << endl;

    return 0;
}
