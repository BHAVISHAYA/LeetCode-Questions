class Solution {
public:
    bool isOkay(int mid, vector<int> &position, int m) {
        int countOfBallsPlaced = 1, prevIndex = 0;
        for(int i = 1 ; i < position.size() ; i++) {
            if(position[i] - position[prevIndex] >= mid) {
                countOfBallsPlaced++;
                prevIndex = i;
            }
        }
        return (countOfBallsPlaced >= m);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int start = 0;
        int end = *max_element(position.begin(), position.end());
        int ans = -1;
        while(start <= end) {
            int mid = ((start) + ((end - start) / 2));
            if(isOkay(mid, position, m)) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};