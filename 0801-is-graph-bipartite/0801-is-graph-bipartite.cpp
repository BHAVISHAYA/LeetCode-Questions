class Solution {
public:
    bool bfs(int node, vector<int> &vis, vector<int> adj[]) {
        queue<int> q;
        q.push(node);
        vis[node] = 0;
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            for(auto &value: adj[n]) {
                if(vis[value] == -1) {
                    vis[value] = !vis[n];
                    q.push(value);
                } else if(vis[value] == vis[n]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        for(int i = 0 ; i < graph.size() ; i++) {
            for(int j = 0 ; j < graph[i].size() ; j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        for(int i = 0 ; i < V ; i++) {
            cout << i << " => ";
            for(auto &value: adj[i]) {
                cout << value << " ";
            }
            cout << endl;
        }
        vector<int> color(V, -1);
        for(int i = 0 ; i < V ; i++) {
            if(color[i] == -1) {
                if(bfs(i, color, adj) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};