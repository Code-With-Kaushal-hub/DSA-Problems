class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j=0;
        string p="";
        int ma=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(p.contains(s[i])){
                int k=p.size();
                ma=max(ma,k);
                int idx=p.find(s[i]); 
                j=idx+1;
               p=p.substr(j);
               
            }
            p=p+s[i];
            cout<<p<<"*";
        }
        int k=p.size();
        ma=max(ma,k);
        return ma;
        
    }
};