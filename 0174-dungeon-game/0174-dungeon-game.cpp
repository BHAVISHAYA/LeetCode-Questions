class Solution {
public:
    int minHealthReq(int i, int j, vector<vector<int>> &grid, int currHealth, int minHealth) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return INT_MAX;
        if(i == grid.size() - 1 && j == grid[0].size() - 1) {
            return (minHealth < 0) ? abs(minHealth) + 1 : 1;
        }

        // add current cell point 
        currHealth += grid[i][j];
        minHealth = min(minHealth, currHealth);

        // move right 
        int rightMove = minHealthReq(i, j + 1, grid, currHealth, minHealth);

        int moveDown = minHealthReq(i + 1, j, grid, currHealth, minHealth);

        return min(rightMove, moveDown);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));

        // Base condition just outside destination
        dp[n][m - 1] = dp[n - 1][m] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = max(1, need);
            }
        }
        return dp[0][0];
    }
};