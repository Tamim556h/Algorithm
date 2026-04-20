#include <bits/stdc++.h> //Tamim -BSSE1650  
using namespace std;

const int INF = 1e9;

int main() {
    int a, b;
    int caseNo = 1;

    cout<<"Enter Pages pairs: \n";

    while (true) {
        vector<vector<int>> dist(101, vector<int>(101, INF));
        set<int> nodes;

        cin >> a >> b;
        if (a == 0 && b == 0)
            break;

        
        while (!(a == 0 && b == 0)) {
            dist[a][b] = 1;
            nodes.insert(a);
            nodes.insert(b);
            cin >> a >> b;
        }

        
        for (int i : nodes)
            dist[i][i] = 0;

        
        for (int k : nodes)
            for (int i : nodes)
                for (int j : nodes)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        
        double sum = 0;
        int cnt = 0;

        for (int i : nodes) {
            for (int j : nodes) {
                if (i != j) {
                    sum += dist[i][j];
                    cnt++;
                }
            }
        }

        double avg = sum / cnt;

        cout << "\n Case " << caseNo++ 
             << ": average length between pages = "<< avg
             << " clicks\n";
    }

    return 0;
}
