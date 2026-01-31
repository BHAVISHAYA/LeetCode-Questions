class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int l = 0, r = 0, zeros = 0, maxLen = 0, n = arr.size();
        while (r < n) {
            if (arr[r] == 0) {
                zeros++;
            }
            while (zeros > k) {
                if (arr[l] == 0) {
                    zeros--;
                }
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};