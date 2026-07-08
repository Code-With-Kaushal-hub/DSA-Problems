class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<s.size()&&s[i]==' '){
            i++;
        }
        while(j>=0&&s[j]==' '){
            j--;
        }
        string p="",st="";
        for(int k=i;k<=j;){
            if(s[k]!=' '){
                p=p+s[k];
                k++;
            }
            else{

                st=" "+p+st;

                p="";
                while(s[k]==' '){
                    k++;
                }
            }
        }
        st=p+st;
        return st;
    }
};