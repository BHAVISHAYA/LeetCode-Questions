class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i < 4 ; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == '1' && vis[newRow][newCol] == 0) {
                dfs(newRow, newCol, vis, grid, delRow, delCol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int delRow[] = { -1, 0, 1, 0 };
        int delCol[] = { 0, 1, 0, -1 };
        int ct = 0;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == '1' && vis[i][j] == 0) {
                    dfs(i, j, vis, grid, delRow, delCol);
                    ct++;
                }
            }
        }
        return ct;
    }
};