class Solution {
public:
    int maxDepth(string s) {
        int count =0;
        int ma=0;
        for(char i:s){
            if(i=='('){
                 count++;
            }
            else if(i==')'){
                count--;
            }
            ma=max(ma,count);
        }
        return ma;
    }
};