class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mx=nums[0];
        int n=nums.size();
        vector<int> vec(n);
        vec[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--){
            vec[i]=min(nums[i],vec[i+1]);
        }
        for(int i=0;i<nums.size();i++){
            
            mx=max(mx,nums[i]);
            if(mx-vec[i]<=k){
                return i;
            }
        
        }
        return -1;
        
    }
};