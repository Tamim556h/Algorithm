#include <stdio.h>
#include <stdlib.h>

struct node {
    char ch;
    int freq;
    struct node *left, *right;
};

struct node* newNode(char ch, int freq) {
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->ch = ch;
    t->freq = freq;
    t->left = t->right = NULL;
    return t;
}

int minIndex(struct node* a[], int n) {
    int min = 0;
    for (int i = 1; i < n; i++)
        if (a[i]->freq < a[min]->freq)
            min = i;
    return min;
}

void print(struct node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        print(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = 1;
        print(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c : ", root->ch);
        for (int i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of characters: ");
    scanf("%d", &n);

    struct node* a[20];

    for (int i = 0; i < n; i++) {
        char ch;
        int f;
        printf("Enter character and frequency: ");
        scanf(" %c %d", &ch, &f);
        a[i] = newNode(ch, f);
    }

    while (n > 1) {
        int i = minIndex(a, n);
        struct node* left = a[i];
        a[i] = a[n - 1];
        n--;

        int j = minIndex(a, n);
        struct node* right = a[j];
        a[j] = a[n - 1];
        n--;

        struct node* temp = newNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;

        a[n] = temp;
        n++;
    }

    int code[20];
    printf("\nHuffman Codes:\n");
    print(a[0], code, 0);

    return 0;
}
