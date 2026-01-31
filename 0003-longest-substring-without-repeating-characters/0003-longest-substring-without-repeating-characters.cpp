class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int l = 0, r = 0, maxLength = 0;
        unordered_map<char, int> m;
        while(r < str.size()) {
            if(m.find(str[r]) != m.end()) {
                if(m[str[r]] >= l) {
                    l = m[str[r]] + 1;
                }
            }
            m[str[r]] = r;
            if(maxLength < (r - l + 1)) {
                maxLength = r - l + 1;
            }
            r++;
        }
        return maxLength;
    }
};