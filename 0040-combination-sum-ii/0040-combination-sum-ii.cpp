class Solution {
public:
    void samadhaan(int i, int sum, int target, vector<int> &nums, vector<int> &subSet, vector<vector<int>> &ans) {
        if(sum == target) {
            ans.push_back(subSet);
            return;
        }
        if(sum > target) return;
        if(i >= nums.size()) return;

        // Pick
        sum += nums[i];
        subSet.push_back(nums[i]);
        samadhaan(i + 1, sum, target, nums, subSet, ans);
        sum -= nums[i];
        subSet.pop_back();

        // Skip
        while((i + 1) < nums.size() && nums[i] == nums[i + 1]) i++;
        samadhaan(i + 1, sum, target, nums, subSet, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ss;
        vector<vector<int>> ans;
        samadhaan(0, 0, target, candidates, ss, ans);
        return ans;
    }
};