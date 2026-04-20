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

// activity selection function
void activitySelection(struct Activity a[], int n) {
    int i, lastFinish;
    int taskNo = 1;

    sortByFinish(a, n);

    printf("\nSelected tasks:\n");

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

    printf("\nTotal selected tasks = %d\n", taskNo - 1);
}

int main() {
    int n, i;
    struct Activity a[100];

    printf("Enter number of activities: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter start time and finish time for activity %d: ", i + 1);
        scanf("%d %d", &a[i].start, &a[i].finish);
    }

    activitySelection(a, n);

    return 0;
}
