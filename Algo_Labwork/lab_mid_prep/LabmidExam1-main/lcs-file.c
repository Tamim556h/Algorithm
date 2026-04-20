#include <stdio.h>
#include <string.h>

int main() {
    FILE *file1, *file2;
    char s1[200], s2[200];
    char words1[50][50], words2[50][50];
    int count1 = 0, count2 = 0;

    // Open first file
    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        printf("Cannot open file1.txt\n");
        return 1;
    }
    fgets(s1, sizeof(s1), file1);
    fclose(file1);
    s1[strcspn(s1, "\n")] = '\0'; // remove newline

    // Open second file
    file2 = fopen("file2.txt", "r");
    if (file2 == NULL) {
        printf("Cannot open file2.txt\n");
        return 1;
    }
    fgets(s2, sizeof(s2), file2);
    fclose(file2);
    s2[strcspn(s2, "\n")] = '\0'; // remove newline

    // Split first sentence into words
    char *token = strtok(s1, " ");
    while (token != NULL) {
        strcpy(words1[count1++], token);
        token = strtok(NULL, " ");
    }

    // Split second sentence into words
    token = strtok(s2, " ");
    while (token != NULL) {
        strcpy(words2[count2++], token);
        token = strtok(NULL, " ");
    }

    printf("Common words are:\n");

    int commonCount = 0;

    for (int i = 0; i < count1; i++) {
        for (int j = 0; j < count2; j++) {
            if (strcmp(words1[i], words2[j]) == 0) {
                printf("%s\n", words1[i]);
                words2[j][0] = '\0'; // mark as used
                commonCount++;
                break;
            }
        }
    }

    printf("\nNumber of common words = %d\n", commonCount);

    return 0;
}
