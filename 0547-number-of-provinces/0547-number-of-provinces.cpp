class Solution {
public:
    void dfs(int startNode, vector<int> &vis, vector<int> adj[]) {
        vis[startNode] = 1;
        for(auto &value: adj[startNode]) {
            if (vis[value] == 0) {
                dfs(value, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        vector<int> adj[isConnected.size()];
        for(int i = 0 ; i < isConnected.size() ; i++) {
            for(int j = 0 ; j < isConnected[i].size() ; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(isConnected.size(), 0);
        for(int i = 0 ; i < isConnected.size() ; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj);
                provinces++;
            }
        }
        return provinces;
    }
};