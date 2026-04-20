#include <stdio.h>
#include <stdlib.h>

struct node {
    char ch;
    int freq;
    struct node *left, *right;
};

struct node* newNode(char ch, int f) {
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->ch = ch;
    t->freq = f;
    t->left = t->right = NULL;
    return t;
}

int min(struct node* a[], int n) {
    int m = 0;
    for (int i = 1; i < n; i++)
        if (a[i]->freq < a[m]->freq)
            m = i;
    return m;
}

void printCode(struct node* r, int code[], int top) {
    if (r->left) {
        code[top] = 0;
        printCode(r->left, code, top + 1);
    }
    if (r->right) {
        code[top] = 1;
        printCode(r->right, code, top + 1);
    }
    if (!r->left && !r->right) {
        printf("%c : ", r->ch);
        for (int i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}

int main() {
    // predefined input
    char ch[] = {'A', 'B', 'C', 'D'};
    int freq[] = {5, 9, 12, 13};
    int n = 4;

    struct node* a[10];

    for (int i = 0; i < n; i++)
        a[i] = newNode(ch[i], freq[i]);

    while (n > 1) {
        int i = min(a, n);
        struct node* left = a[i];
        a[i] = a[n - 1];
        n--;

        int j = min(a, n);
        struct node* right = a[j];
        a[j] = a[n - 1];
        n--;

        struct node* t = newNode('$', left->freq + right->freq);
        t->left = left;
        t->right = right;

        a[n] = t;
        n++;
    }

    int code[10];
    printf("Huffman Codes:\n");
    printCode(a[0], code, 0);

    return 0;
}
