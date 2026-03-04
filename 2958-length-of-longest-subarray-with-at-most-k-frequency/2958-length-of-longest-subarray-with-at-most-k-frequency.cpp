class Solution {
public:
    int maxSubarrayLength(vector<int>& arr, int k) {
        int i = 0, j = 0, ans = 0, n = arr.size();
        unordered_map<int, int> m; 
        while(j < n) {
            m[arr[j]]++;
            while(i <= j && m[arr[j]] > k) {
                m[arr[i]]--;
                if(m[arr[i]] == 0) {
                    m.erase(arr[i]);
                }
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};