class Solution {
public:
    int calculate(string s) {
        long long number=0;
        int sign=1;
        long long ans=0;
        int n=s.size();
        stack<long long >st;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                number=number*10+(s[i]-'0');

            }
            else if(s[i]=='+'){
                ans+=(number*sign);
                number=0;
                sign=1;
            }
            else if(s[i]=='-'){
                ans+=(number*sign);
                number=0;
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(ans);
                st.push(sign);
                ans = 0;
                number=0;
                sign=1;
            }
            else if(s[i]==')'){
                ans+=(number*sign);
                int prev_sign=st.top();st.pop();
                int prev_ans=st.top();st.pop();
                ans=(ans*prev_sign)+prev_ans;
                number=0;
            }
        }
        ans += (number * sign);
        return ans;
    }
};