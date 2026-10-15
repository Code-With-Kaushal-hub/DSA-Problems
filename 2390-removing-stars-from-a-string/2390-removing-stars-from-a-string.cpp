class Solution {
public:
    string removeStars(string s) {
          stack<char>st;
        for(char i:s){
           
                if(i=='*'){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            
        }
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};