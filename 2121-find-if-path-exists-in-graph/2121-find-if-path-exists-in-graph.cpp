class Solution {
public:
    void dfs(int source, int destination, vector<int> adj[], vector<int> &vis) {
        vis[source] = 1;
        for(auto &value : adj[source]) {
            if(!vis[value]) {
                dfs(value, destination, adj, vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n == 1) return true;
        if(source == destination) return true;
        vector<int> adj[n];
        for(int i = 0 ; i < edges.size() ; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        // Using DFS technique of a graph
        vector<int> vis(n, 0);
        dfs(source, destination, adj, vis);
        return (vis[destination] == 1);
    }
};