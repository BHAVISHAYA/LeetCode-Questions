class Solution {
public:
    bool ableToEatBeforeGuardReturn(int mid, int h, vector<int> &piles) {
        int ct = 0;
        for(int i = 0 ; i < piles.size() ; i++) {
            if(piles[i] <= mid) ct++;
            else {
                if(piles[i] % mid == 0) ct += piles[i] / mid;
                else ct += ((piles[i] / mid) + 1);
            }
            if(ct > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // sort(piles.begin(), piles.end());
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(start <= end) {
            int mid = ((start) + ((end - start) / 2));
            if(ableToEatBeforeGuardReturn(mid, h, piles)) {
                ans = min(ans, mid);
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};