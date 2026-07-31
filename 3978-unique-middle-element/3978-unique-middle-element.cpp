class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid=nums.size()/2;
        int c=0;
        for(int i:nums){
            if(i==nums[mid]){
                c++;
            }
        }
        return c==1;
        
    }
};