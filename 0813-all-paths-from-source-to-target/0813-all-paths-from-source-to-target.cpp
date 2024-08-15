class Solution {
public:
    void dfs(int src, int des, vector<int> adj[], vector<vector<int>> &ans, vector<int> &v) {
        v.push_back(src);
        if(src == des) {
            ans.push_back(v);
        }
        for(auto &value : adj[src]) {
            dfs(value, des, adj, ans, v);
        }
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> adj[graph.size()];
        for(int i = 0 ; i < graph.size() ; i++) {
            for(int j = 0 ; j < graph[i].size() ; j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        int src = 0, dest = graph.size() - 1;
        vector<vector<int>> ans;
        vector<int> v;
        dfs(src, dest, adj, ans, v);
        return ans;
    }
};