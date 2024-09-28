class Solution {
public:
    //* Recursion Starting from index 0 to last 
    int getLength(int i, int j, string &s1, string &s2) {
        if(i >= s1.size() || j >= s2.size()) return 0;

        if(s1[i] == s2[j]) {
            return 1 + getLength(i + 1, j + 1, s1, s2);
        }
        else {
            return max(getLength(i, j + 1, s1, s2), getLength(i + 1, j, s1, s2));
        }
    }

    //* Recursion Starting from index last to 0
    int getLength1(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) {
            return dp[i][j] = 1 + getLength1(i - 1, j - 1, s1, s2, dp);
        }
        else {
            return dp[i][j] = max(getLength1(i, j - 1, s1, s2, dp), getLength1(i - 1, j, s1, s2, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int> (text2.size() + 1, -1));
        return getLength1(text1.size() - 1, text2.size() - 1, text1, text2, dp);
    }
};