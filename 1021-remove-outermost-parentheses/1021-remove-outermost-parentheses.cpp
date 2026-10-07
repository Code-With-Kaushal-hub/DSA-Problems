class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int>st;
        string ans="";
        string p="";
        for(char i:s){
            if(i=='('){
                st.push(i);
                if(st.size()>1){
                    ans+='(';
                }
            }
            else if(!st.empty()&&(st.top()=='('&&i==')')){
                char x=st.top();
                st.pop();
                if(!st.empty()){
                    ans+=")";
                }
            }
            
        }
        
        return ans;

    }
};