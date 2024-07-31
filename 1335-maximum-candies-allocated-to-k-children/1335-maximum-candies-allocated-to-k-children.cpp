class Solution {
public:
    bool ableToGiveEqualCandiesToKChildrens(vector<int> &candies, long long k, int mid) {
        long long ct = 0;
        for(int i = 0 ; i < candies.size() ; i++) {
            ct += (candies[i] / mid);
            if(ct >= k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int start = 1, end = *max_element(candies.begin(), candies.end()), ans = 0;
        while(start <= end) {
            int mid = ((start) + ((end - start) / 2));
            if(ableToGiveEqualCandiesToKChildrens(candies, k, mid)) {
                if(ans < mid) {
                    ans = mid;
                }
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};