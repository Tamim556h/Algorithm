#include <bits/stdc++.h> //Tamim BSSE1650
using namespace std;

struct TrieNode {
    char ch;
    TrieNode *left, *right;

    TrieNode() {
        ch = '\0';
        left = right = nullptr;
    }
};

int main() {
    ifstream fin("compressed.bin", ios::binary);
    ifstream codeFile("codes.txt");
    ofstream fout("decompressed.txt", ios::binary);

    //read huffman codes
    map<char,string> huffmanCode;
    string line;
    while (getline(codeFile, line)) {
        if(line.length() < 3) continue;

        char ch;
        string code;

        if(line[0] == ' ') {
            ch = ' ';
            code = line.substr(2);
        } 
        else {
            ch = line[0];
            code = line.substr(2);
        }
        huffmanCode[ch] = code;
    }

    // building  decoding trie
    TrieNode* root = new TrieNode();
    for (auto &p : huffmanCode) {
        TrieNode* node = root;
        for (char b : p.second) {
            if (b == '0') {
                if (!node->left) node->left = new TrieNode();
                node = node->left;
            } 
            else {
                if (!node->right) node->right = new TrieNode();
                node = node->right;
            }
        }
        node->ch = p.first;
    }

    // read compressed file
    int padding = fin.get();
    string bits;
    char byte;
    while (fin.get(byte)) {
        bitset<8> b(byte);
        bits += b.to_string();
    }

    // remove padding
    bits = bits.substr(0, bits.size() - padding);

    // Decode
    TrieNode* node = root;
    for (char b : bits) {
        node = (b == '0') ? node->left : node->right;
        if (!node->left && !node->right) {
            fout.put(node->ch);
            node = root;
        }
    }

    fin.close();
    fout.close();

    cout << "File decompressed.\n";
    return 0;
}
