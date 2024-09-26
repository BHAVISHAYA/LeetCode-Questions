class Solution {
public:
    int encrypt(int num) {
        int ct = 0, mx = 0;
        while(num != 0) {
            mx = max(mx, num % 10);
            ct++;
            num = num / 10;
        }
        int rev = 0;
        while(ct--) {
            rev = (rev * 10) + mx;
        }
        return rev;
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            sum += encrypt(nums[i]);
        }
        return sum;
    }
};