class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int ans = 0, sum = 0;
        sort(capacity.rbegin(), capacity.rend());
        for(int i = 0 ; i < apple.size() ; i++) {
            sum += apple[i];
        }
        for(int i = 0 ; i < capacity.size() ; i++) {
            if(sum > 0) {
                sum -= capacity[i];
                ans++;
            }
        }
        return ans;
    }
};