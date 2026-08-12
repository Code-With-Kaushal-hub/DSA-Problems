class Solution {
public:
    int c=0;
    int fun(int i,int j,int m,int n,vector<vector<int>>& vec) {

        if (i==m&&j==n)
        
            return 1;
        if(i>m||j>n){
            return 0;
        }
        if(vec[i][j]!=-1){
            return vec[i][j];
        }
        
        int l = fun(i+1,j,m,n,vec);
        int r = fun(i,j+1,m,n,vec);

       vec[i][j]=l+r;

        return l+r;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> vec(m+1,vector<int>(n+1,-1));
        return fun(1,1,m,n,vec);
    }
};