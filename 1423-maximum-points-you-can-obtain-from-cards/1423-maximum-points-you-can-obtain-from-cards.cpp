class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < k; i++) {
            leftSum += arr[i];
        }

        long long int maxSum = leftSum + rightSum;
        int r = n - 1;

        for (int i = k - 1; i >= 0; i--) {
            leftSum -= arr[i];
            rightSum += arr[r];
            if(maxSum < (leftSum + rightSum)) {
                maxSum = leftSum + rightSum;
            }
            r--;
        }

        return maxSum;
    }
};