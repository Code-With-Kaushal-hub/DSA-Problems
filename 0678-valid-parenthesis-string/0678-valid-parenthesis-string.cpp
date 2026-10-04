class Solution {
public:
    bool checkValidString(string s) {
        stack<int> p;     
        stack<int> star;  

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                p.push(i);
            } 
            else if (s[i] == '*') {
                star.push(i);
            } 
            else { // s[i] == ')'
                if (!p.empty()) {
                    p.pop();
                } 
                else if (!star.empty()) {
                    star.pop();
                } 
                else {
                    return false;
                }
            }
        }

       
        while (!p.empty() && !star.empty()) {
            if (p.top() > star.top()) { 
                return false;
            }
            p.pop();
            star.pop();
        }

        return p.empty();
    }
};