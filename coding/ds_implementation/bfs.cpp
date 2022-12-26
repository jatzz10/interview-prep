class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vec;
        bool visited[V];
        queue<int> q;
        // taking first element of graph as 0
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()) {
            int s = q.front();
            vec.push_back(s);
            q.pop();
            
            for (int i = 0; i < adj[s].size(); i++) {
                if (!visited[adj[s][i]]) {
                    q.push(adj[s][i]);
                    visited[adj[s][i]] = true;
                }
            }
        }
        return vec;
    }
};