class Solution {
public:
    static bool comp(string &a,string &b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {

       vector<string>s;
        for(int i:nums){
            s.push_back(to_string(i));
            
        }
        sort(s.begin(), s.end(),comp);  
        string a="";
        int t=0;
        for(string i:s){
            a=a+i;
            if(i!="0"){
                t=1;
            }
        }
        if(t==1){
            return a;
        }
        return "0";
    }
};