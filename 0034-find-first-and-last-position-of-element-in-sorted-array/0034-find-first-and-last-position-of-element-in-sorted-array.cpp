class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int t=1;
        int p;
        while(low<=high){
             int mid=low+(high-low)/2;
             
             
             if(target<=nums[mid]){
                p=mid;
                 high=mid-1;
                 if(nums[mid]==target){
                    t=0;
                 }
             }
             else{
                low=mid+1;
             }
        }
        vector<int>vec;
        if(t==0){
            vec.push_back(p);
        }
        else{
            vec.push_back(-1);
        }
        
        low=0;
        high=nums.size()-1;
        int ans;
        t=1;
       while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
            if(nums[mid]==target){
                    t=0;
                 }
        }
        }
        if(t==0){
            vec.push_back(high);
        }
        else{
            vec.push_back(-1);
        }
        return vec;
        
    }
};