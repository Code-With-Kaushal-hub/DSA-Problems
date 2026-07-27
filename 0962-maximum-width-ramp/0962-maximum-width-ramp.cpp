class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n = nums.size();
        stack<int> s;

        // Build decreasing stack
        for (int i = 0; i < n; i++) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }

        int ans = 0;

        // Scan from right to left
        for (int i = n - 1; i >= 0 && !s.empty(); i--) {

            while (!s.empty() && nums[i] >= nums[s.top()]) {
                ans = max(ans, i - s.top());
                s.pop();
            }
        }

        return ans;
    }
};