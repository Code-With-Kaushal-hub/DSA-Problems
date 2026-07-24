class Solution {
public:
    bool fun(vector<int>& arr, int k,long long cap) {
        int noofstudents=1;
        long long pages=0;

        for (int i = 0; i < arr.size(); i++) {
            if (pages+arr[i]<= cap) {
                pages+=arr[i];
                
            }
            else{
                noofstudents++;
                pages=arr[i];
            }
        }

        if (noofstudents > k){
            return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        if(nums.size()<k){
            return -1;
        }
            int ma=INT_MIN;
            long long sum=0;
        for(int i=0;i<nums.size();i++){
            ma=max(ma,nums[i]);
            sum=sum+nums[i];
        }
        
      
        long long low=ma;
            long long high=sum;
    
        while (low<= high) {

                long long mid = low +(high - low) / 2;

            if (fun(nums,k, mid)) {
            
                high = mid - 1;
            } else {
                
                low = mid + 1;
            }
        }

        return low;// code herenums
        
    }
};