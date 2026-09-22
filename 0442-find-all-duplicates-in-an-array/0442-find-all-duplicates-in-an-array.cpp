class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int>s;
        for(int i:nums){
            if(s.count(i)){
                ans.push_back(i);
            }
            else{
                s.insert(i);
            }
        }
        return ans;
    }
};