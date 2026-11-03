class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ma=*max_element(nums.begin(),nums.end());
        int count=0;
        for(int i:nums){
            count+=ma-i;
        }
        return count;
    }
};