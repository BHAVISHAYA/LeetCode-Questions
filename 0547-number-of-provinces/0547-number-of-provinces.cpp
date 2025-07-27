class Solution {
public:
    void dfs(int startNode, vector<int> adj[], vector<int> &vis) {
        vis[startNode] = 1;
        for(auto &value: adj[startNode]) {
            if(vis[value] == 0) {
                
                // vis[value] = 1;
                dfs(value, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[graph.size() + 1];
        for(int i = 0 ; i < graph.size() ; i++) {
            for(int j = 0 ; j < graph[i].size() ; j++) {
                if(graph[i][j] == 1) {
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }
        vector<int> vis(V + 1, 0);
        int ans = 0;
        for(int i = 1 ; i < (V + 1) ; i++) {
            if(vis[i] == 0) {
                dfs(i, adj, vis);
                ans++;
            }
        }
        return ans;
    }
};