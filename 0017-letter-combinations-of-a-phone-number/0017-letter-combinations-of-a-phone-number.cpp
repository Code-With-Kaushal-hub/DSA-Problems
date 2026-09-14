class Solution {
public:
    vector<string>g;
    vector<string>h={
            "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
    

        
        void letter(string &digits,int n,string curr){
            
            if(n==digits.size()){
                g.push_back(curr);
                return ;
            }
            int i=digits[n]-'2';
            
        
            for(char j:h[i]){
                letter(digits,n+1,curr+j);
        
            
                }

        } 
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        letter(digits,0,"");
        return g;
        
    }
};