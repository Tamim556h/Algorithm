#include <stdio.h>

struct Activity {
    int start;
    int finish;
};

// sort activities by finish time
void sortByFinish(struct Activity a[], int n) {
    int i, j;
    struct Activity temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i].finish > a[j].finish) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void activitySelection(struct Activity a[], int n) {
    int i, lastFinish;
    int taskNo = 1;   // task counter

    sortByFinish(a, n);

    printf("Selected tasks:\n");

    // first task
    printf("Task %d : (%d, %d)\n", taskNo, a[0].start, a[0].finish);
    lastFinish = a[0].finish;
    taskNo++;

    // remaining tasks
    for (i = 1; i < n; i++) {
        if (a[i].start >= lastFinish) {
            printf("Task %d : (%d, %d)\n", taskNo, a[i].start, a[i].finish);
            lastFinish = a[i].finish;
            taskNo++;
        }
    }
}

int main() {
    struct Activity a[] = {
        {1, 3},
        {2, 5},
        {4, 6},
        {6, 8},
        {5, 9}
    };

    int n = sizeof(a) / sizeof(a[0]);

    activitySelection(a, n);

    return 0;
}
