#include <bits/stdc++.h>  //Tamim -BSSE1650
using namespace std;

const int INF = 1e9;

int main() {
    int C, S, Q;
    int caseNo = 1;
    cout<<" Enter C {Crossings} , S {streets} and   Q {queries} : \n";

    while (cin >> C >> S >> Q) {

        if (C == 0 && S == 0 && Q == 0)
            break;

        vector<vector<int>> dist(C + 1, vector<int>(C + 1, INF));

        
        for (int i = 1; i <= C; i++)
            dist[i][i] = 0;

        for (int i = 0; i < S; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            dist[a][b] = dist[b][a] = d;
        }

        for (int k = 1; k <= C; k++) {
            for (int i = 1; i <= C; i++) {
                for (int j = 1; j <= C; j++) {
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));   // main idea
                }
            }
        }

        cout << "\nCase #" << caseNo++ << "\n";

        while (Q--) {
            int u, v;
            cin >> u >> v;
            if (dist[u][v] == INF)
                cout << "no path\n";
            else
                cout << dist[u][v] << "\n";
        }

        cout << "\n";
    }

    return 0;
}
