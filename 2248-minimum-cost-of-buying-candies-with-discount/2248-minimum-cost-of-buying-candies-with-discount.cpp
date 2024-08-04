class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size(), count = 0;
        int buy = n-1, free = n-3;
        while(buy >= 0) {
            count += cost[buy];
            if(buy > 0){
                count += cost[buy-1];
            }
            buy -= 3;
        }
        return count;
    }
};