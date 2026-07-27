class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
        int j=1;
        int count=0;
        int i=0;
        while (j < nums.size()) {
            if (i== j ||nums[j]- nums[i] < k) {
                j++;
            }
            else if (nums[j] -nums[i] > k) {
                i++;
            }
            else {
                count++;
                i++;
                j++;

                while (i < nums.size() && nums[i] == nums[i - 1])
                    i++;

                while (j < nums.size() && j > 0 && nums[j] == nums[j - 1])
                    j++;
            }
        }
        return count;
    }
};