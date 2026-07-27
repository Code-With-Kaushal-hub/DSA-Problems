class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        set<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {

            for (int j = i + 1; j < n - 2; j++) {

                unordered_set<long long> seen;

                for (int k = j + 1; k < n; k++) {

                    long long need = 1LL * target - nums[i] - nums[j] - nums[k];

                    if (seen.count(need)) {
                        ans.insert({(int)need, nums[i], nums[j], nums[k]});
                    }

                    seen.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};