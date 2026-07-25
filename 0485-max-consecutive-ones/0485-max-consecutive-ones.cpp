class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int ma=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                
            }
            else{
                ma=max(ma,count);
                count=0;
            }
        }
        ma=max(ma,count);
        return ma;
    }
};