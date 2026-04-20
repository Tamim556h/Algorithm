#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};


Node* newNode(char ch, int freq) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

/* Comparator for priority queue (min-heap) */
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root) return;

    // Leaf node
    if (!root->left && !root->right) {
        cout << root->ch << " : " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++)
        cin >> chars[i];

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Step 1: Create leaf nodes
    for (int i = 0; i < n; i++)
        pq.push(newNode(chars[i], freq[i]));

    // Step 2: Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = newNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    // Root of Huffman Tree
    Node* root = pq.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}
