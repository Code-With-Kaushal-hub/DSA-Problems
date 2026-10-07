class Solution {
public:
    string removeOuterParentheses(string s) {
        int op=0,cl=0;
        int i=0,j=0;
        string ans;
        while(j<s.size()){
            if(s[j]=='('){
                op++;
            }
            else{
                cl++;
            }
            if(op==cl){
                ans+=s.substr(i+1,j-i-1);
                op=0;cl=0;i=j+1;
            }
            j++;
        }
        return ans;
    }
};