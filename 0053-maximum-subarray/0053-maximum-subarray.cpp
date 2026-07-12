class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
        int sum=0,cur=0;
        int mx=INT_MIN;
        for(int i: nums){
            cur=max(cur+i,i);
            mx=max(mx,cur);
        }
       return mx;
    }
};