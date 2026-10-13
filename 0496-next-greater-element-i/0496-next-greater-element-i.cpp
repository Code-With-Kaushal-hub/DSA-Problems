class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        map<int,int>m;
        for(int i:nums2){
           
            while(!s.empty()&&s.top()<i){
                    m[s.top()]=i;
                    s.pop();
                }
            
            s.push(i);
        }
        vector<int> ans;
        for(int i:nums1){
            if(m.count(i)){
                ans.push_back(m[i]);
            }
            else{
                 ans.push_back(-1);
            }
        }
        return ans;
    }
};