class Solution {
public:
    bool isConnected(vector<int> &connComp, vector<int> adj[]) {
        for(int i = 0 ; i < connComp.size() ; i++) {
            if(adj[connComp[i]].size() != connComp.size() - 1) return false;
        }
        return true;
    }

    void dfs(int start, vector<int> adj[], vector<int> &vis, vector<int> &connComp) {
        vis[start] = 1;
        connComp.push_back(start);
        for(auto &value : adj[start]) {
            if(!vis[value]) {
                dfs(value, adj, vis, connComp);
            }
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i = 0 ; i < edges.size() ; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, 0);
        int ct = 0;
        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) {
                vector<int> connComp;
                dfs(i, adj, vis, connComp);
                if(isConnected(connComp, adj)) {
                    ct++;
                }
            }
        }
        return ct;
    }
};