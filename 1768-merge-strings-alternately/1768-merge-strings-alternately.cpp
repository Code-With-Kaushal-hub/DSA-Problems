class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s=max(word1.size(),word2.size());
        string ans="";
        for(int i=0;i<s;i++){
            if(i<word1.size()){
                  ans=ans+word1[i];
            }
            if(i<word2.size()){
                  ans=ans+word2[i];
            }
        }
        return ans;
    }
};