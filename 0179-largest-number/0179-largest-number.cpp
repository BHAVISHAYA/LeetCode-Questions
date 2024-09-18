class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() <= 1) return to_string(nums[0]);
        string ans = "";
        for(int i = 0 ; i < nums.size() - 1 ; i++) {
            for(int j = i + 1 ; j < nums.size() ; j++) {
                string s1 = ""; 
                s1 += to_string(nums[i]);
                string s2 = "";
                s2 += to_string(nums[j]);

                string s3 = s1;
                s3 += s2;

                string s4 = s2;
                s4 += s1;

                if(s3 <= s4) swap(nums[i], nums[j]);
            }
        }
        for(int i = 0 ; i < nums.size() ; i++) {
            ans += to_string(nums[i]);
        }
        if(count(ans.begin(), ans.end(), '0') == ans.size()) return "0";
        return ans;
    }
};