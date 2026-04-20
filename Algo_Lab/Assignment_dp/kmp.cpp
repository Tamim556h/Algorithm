#include <bits/stdc++.h>
using namespace std;


void computeLPS(const string& pattern, vector<int>& lps) {
    int m = pattern.length();
    lps[0] = 0;

    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m);
    computeLPS(pattern, lps);

    int i = 0; 
    int j = 0; 

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; 
        } 
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    cout << "Search complete." << endl;
}

int main(){

    string text, pattern;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    KMPSearch(text, pattern);

    return 0;
}
