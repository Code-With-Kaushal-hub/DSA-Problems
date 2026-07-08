class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> se={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int c=0,p=0;
        for(int i=0;i<s.size()/2;i++){
            if(se.count(s[i])){
                c++;
            }
        }
         for(int i=s.size()/2;i<s.size();i++){
            if(se.count(s[i])){
                p++;
            }
        }
        return c==p;
    }
};