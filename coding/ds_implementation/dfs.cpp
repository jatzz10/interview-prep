#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    map<int, bool> visited;
    map<int, vector<int>> adj;

    void addEdge(int u, int v);

    void dfs(int s);
};

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::dfs(int s) {
    visited[s] = true;
    cout << s << " ";
    for (int i = 0; i < adj[s].size(); i++) {
        if (!visited[adj[s][i]]) {
            dfs(adj[s][i]);
        }
    }
}


int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.dfs(0);
    return 0;
}