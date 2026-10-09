class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        // Base case
        if (i >= nums.size()) {
            return 0;
        }

        // If already calculated, return stored answer
        if (dp[i] != -1) {
            return dp[i];
        }

        // Choice 1: Rob the current house
        int rob = nums[i] + solve(nums, i + 2, dp);

        // Choice 2: Skip the current house
        int skip = solve(nums, i + 1, dp);

        // Store and return the maximum
        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};