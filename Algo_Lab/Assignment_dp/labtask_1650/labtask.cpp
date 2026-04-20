#include <bits/stdc++.h>    // Tamim -bsse1650
using namespace std;

const int INF = 1e9;
int graph[100][100]; 

int n; 

bool bfs(int s, int t, vector<int>& parent) {
    for (int i = 0; i < n; i++){
        parent[i] = -1;
    }
    
    queue<int> q;
    q.push(s);
    parent[s] = s;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (parent[v] == -1 && graph[u][v] > 0) {
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return parent[t] != -1;
}

int maxFlow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);

    while (bfs(s, t, parent)) {
        int minflow = INF;

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            minflow = min(minflow, graph[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            graph[u][v] -= minflow;
            graph[v][u] += minflow;
        }

        flow += minflow;
    }
    return flow;
}

int main() {
    int edges;
    int source, sink;

    cout<<"Enter number of nodes, source, sink and number of edges: ";
    cin >> n;           
    cin >> source >> sink >> edges;

    source--; 
    sink--;

    for (int i = 0; i < edges; i++) {
        int u, v, cap;
        cout << "Enter edge (u v capacity): ";
        cin >> u >> v >> cap;
        u--; v--; 
        graph[u][v] = cap;
    }

    cout << "The bandwidth is " << maxFlow(source, sink) << endl;

    return 0;
}
