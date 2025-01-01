class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        int ct = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] < k) ct++;
        }
        return ct;
    }
};