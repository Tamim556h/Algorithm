#include <stdio.h>
#include <string.h>

int main() {
    char s1[200], s2[200];
    char words1[50][50], words2[50][50];
    int count1 = 0, count2 = 0;

    printf("Enter first sentence:\n");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // remove newline

    printf("Enter second sentence:\n");
    fgets(s2, sizeof(s2), stdin);
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

    printf("\nCommon words are:\n");

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
