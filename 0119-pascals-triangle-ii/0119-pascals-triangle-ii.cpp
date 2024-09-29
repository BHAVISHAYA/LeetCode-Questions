class Solution {
public:
    void generateTriangle(int i, int n, vector<vector<int>> &ans) {
        if(i >= n) return;
        vector<int> temp(i + 1, 1);
        for(int j = 1 ; j < temp.size() - 1 ; j++) {
            temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        ans.push_back(temp);
        temp.clear();
        generateTriangle(i + 1, n, ans);
    }
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        generateTriangle(0, rowIndex + 1, ans);
        return ans[rowIndex];
    }
};