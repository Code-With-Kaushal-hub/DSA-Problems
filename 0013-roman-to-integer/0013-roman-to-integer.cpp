class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        char pre;
        for(char i:s){
            if(pre){
                if(m[pre]<m[i]){
                    cout<<i<<" ";
                    ans=ans-m[pre];
                    ans=ans+(m[i]-m[pre]);
                    cout<<" "<<ans<<endl;

                } 
                else{
                    ans=ans+m[i];
                }  
            }
            else{
            ans=ans+m[i];}
            pre=i;
        }
        return ans;
    }
};