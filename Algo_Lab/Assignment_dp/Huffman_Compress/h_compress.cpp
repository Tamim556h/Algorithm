#include <bits/stdc++.h>  //Tamim BSSE1650
using namespace std;

int main() {
    ifstream fin("input.txt", ios::binary);
    ifstream codeFile("codes.txt");
    ofstream fout("compressed.bin", ios::binary);

    // read huffman codes
    map<char,string> huffmanCode;
    string line;
    while (getline(codeFile, line)) {
        if(line.length() < 3) continue; // invalid line

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
        

    // encode input
    string bits;
    char c;
    while (fin.get(c)) {
        bits += huffmanCode[c];
    }

    // adding padding
    int padding = (8 - bits.size() % 8) % 8;
    bits.append(padding, '0');

    // save padding info
    fout.put(padding);

    // write binary data
    for (size_t i = 0; i < bits.size(); i += 8) {
        bitset<8> b(bits.substr(i, 8));
        fout.put((char)b.to_ulong());
    }

    fin.close();
    fout.close();

    cout << "File compressed.\n";
    return 0;
}
