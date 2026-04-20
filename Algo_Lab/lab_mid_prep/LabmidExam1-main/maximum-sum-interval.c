#include <stdio.h>

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int max_so_far = arr[0];
    int max_ending_here = arr[0];

    int start = 0, end = 0, s = 0;

    for(int i = 1; i < n; i++){
        if(arr[i] > max_ending_here + arr[i]){
            max_ending_here = arr[i];
            s = i; // potential start of new subarray
        } else {
            max_ending_here = max_ending_here + arr[i];
        }

        if(max_ending_here > max_so_far){
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
    }

    printf("Maximum Sum = %d\n", max_so_far);
    printf("Maximum Sum Subarray = [ ");
    for(int i = start; i <= end; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");

    return 0;
}
