class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        int r=nums.size()-1;
        int count=0;
        int l=0;
        while(l<r){
            while(l!=r){
                if(nums[r]-nums[l]==k){
                    vector<int>v={nums[l],nums[r]};
                    sort(v.begin(),v.end());
                    s.insert(v);
                }
                
                 r--;
            }
            l++;
    
            r=nums.size()-1;
           
            
        
        }
        return s.size();
    }
};