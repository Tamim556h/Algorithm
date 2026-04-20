#include <stdio.h>

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {
    // Predefined array
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    int lis[n], prev[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        lis[i] = 1;     // every element is a subsequence of length 1
        prev[i] = -1;   // previous element index in LIS
    }

    // Compute LIS
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j; // store previous index
            }
        }
    }

    // Find maximum length and its index
    int maxLIS = lis[0], index = 0;
    for (int i = 1; i < n; i++) {
        if (lis[i] > maxLIS) {
            maxLIS = lis[i];
            index = i;
        }
    }

    // Reconstruct LIS
    int sequence[maxLIS];
    int k = maxLIS - 1;
    while (index != -1) {
        sequence[k] = arr[index];
        k--;
        index = prev[index];
    }

    // Print LIS
    printf("Length of LIS = %d\n", maxLIS);
    printf("LIS elements: ");
    for (int i = 0; i < maxLIS; i++)
        printf("%d ", sequence[i]);
    printf("\n");

    return 0;
}
