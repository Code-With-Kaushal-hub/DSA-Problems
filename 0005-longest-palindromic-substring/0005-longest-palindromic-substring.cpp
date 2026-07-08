class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        for(int k=0;k<s.size();k++){
            string temp;
            int i=k-1;
            int j=k+1;
            temp=s[k];
            while(i>=0&&j<s.size()){
                if(s[i]==s[j]){
                    temp=s[i]+temp+s[j];
                    i--;
                    j++;
                }
                else{
                    break;
                }
               
            }
            if(ans.size()<temp.size()){
                ans=temp;
            }
            i=k-1;
            j=k;
            temp="";
            while(i>=0&&j<s.size()){
                if(s[i]==s[j]){
                    temp=s[i]+temp+s[j];
                    i--;
                    j++;
                }
                else{
                    break;
                }
            }
            if(ans.size()<temp.size()){
                ans=temp;
            }
        }
        return ans;

        
    }
};