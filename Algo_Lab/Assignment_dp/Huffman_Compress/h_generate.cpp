#include <bits/stdc++.h>  //Tamim BSSE1650
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// min heap comparison using priority queue
struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// generateing  huffman codes
void buildCodes(Node* root, string code, map<char,string> &huffmanCode) {
    if (!root) return;

    // leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code.empty() ? "0" : code;
    }

    buildCodes(root->left, code + "0", huffmanCode);
    buildCodes(root->right, code + "1", huffmanCode);
}

int main() {
    ifstream fin("input.txt", ios::binary);
    string text((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();

    map<char,int> freq;
    for (char c : text){
        freq[c]++;
    }

    // building priority queue
    priority_queue<Node*, vector<Node*>, cmp> pq;
    for (auto &p : freq){
        pq.push(new Node(p.first, p.second));
    }

    // building  huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node* root = pq.top();

    //building  huffman codes
    map<char,string> huffmanCode;
    buildCodes(root, "", huffmanCode);

    //save codes to file    
    ofstream fout("codes.txt");
    for (auto &p : huffmanCode){
        fout << p.first << " " << p.second << "\n";
    }
    fout.close();

    cout << "Huffman codes generated.\n";
    return 0;
}
