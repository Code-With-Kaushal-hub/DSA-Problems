class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        unordered_map<int, int> m;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (m[nums[right]] == 0)
                k--;

            m[nums[right]]++;

            while (k < 0) {
                m[nums[left]]--;
                if (m[nums[left]] == 0)
                    k++;
                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};