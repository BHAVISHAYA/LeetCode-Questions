class Solution {
public:
    int solve(int i, string &s, int ans, vector<int> &dp) {
        if(i >= s.size()) {
            ans++;
            return dp[i] = ans;
        }
        if(s[i] == '0') return ans;
        if(dp[i] != -1) return dp[i];
        // Take Single Element 
        int ans1= solve(i + 1, s, ans, dp);
        // Take Double Element if <= 26
        int ans2 = 0; 
        if((i + 1) < s.size()) {
            if(s[i] == '1') ans2 = solve(i + 2, s, ans, dp);
            else if(s[i] == '2' && s[i + 1] != '7' && s[i + 1] != '8' && s[i + 1] != '9') ans2 = solve(i + 2, s, ans, dp);
        }

        return dp[i] = ans1 + ans2;
    }
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        if(s.size() == 1) return 1;
        vector<int> dp(s.size() + 1, -1);
        return solve(0, s, 0, dp); 
    }
};