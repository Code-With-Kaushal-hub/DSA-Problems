class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n = nums.size();

        vector<int> premax(n);

        int ma = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            ma = max(ma, nums[i]);
            premax[i] = ma;
        }

        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {

            while (i < j && nums[i] > premax[j])
                i++;

            ans = max(ans, j - i);

            j++;
        }

        return ans;
    }
};