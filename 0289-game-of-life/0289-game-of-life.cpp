class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(n, vector<int> (m, 0));
        int delRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delCol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                int ct = 0;
                for(int k = 0 ; k < 8 ; k++) {
                    int nrow = i + delRow[k];
                    int ncol = j + delCol[k];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 1) {
                        ct++;
                    }
                }
                if(board[i][j] == 1) {
                    if(ct < 2) ans[i][j] = 0;
                    else if(ct == 2 || ct == 3) ans[i][j] = 1;
                    else if(ct > 3) ans[i][j] = 0;
                    else ans[i][j] = board[i][j];
                }
                else {
                    if(ct == 3) ans[i][j] = 1;
                    else ans[i][j] = board[i][j];
                }
            }
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                board[i][j] = ans[i][j];
            }
        }
    }
};