class Solution {
public:
    long long minimumSteps(string s) {
        long long int ans = 0;
        vector<long long int> pf(s.size(), 0);
        for(int i = 0 ; i < s.size() ; i++) {
            if(i == 0) {
                if(s[i] == '1') {
                    pf[i] = 1;
                }
            }
            else {
                if(s[i] == '1') {
                    pf[i] = pf[i - 1] + 1;
                }
                else {
                    pf[i] = pf[i - 1];
                }
            }
        }
        for(int i = 0 ; i < pf.size() ; i++) {
            if(s[i] == '0') {
                ans += pf[i];
            }
        }
        return ans;
    }
};