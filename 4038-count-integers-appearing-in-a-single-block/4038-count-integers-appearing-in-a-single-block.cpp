class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int ,vector<int>>m;
        int count=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        
        for(auto i:m){
            int t=1;
            for(int j=1;j<i.second.size();j++){
                if(i.second[j]!=i.second[j-1]+1){
                    t=0;
                    break;
                }
            }
            if(t==1){
                count++;
            }
        }
        return count;
    }
};