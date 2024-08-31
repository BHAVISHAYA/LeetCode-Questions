class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        for(auto &value : nums) {
            if(value < 10) sum1 += value;
            else sum2 += value;
        }
        return (sum1 != sum2);
    }
};