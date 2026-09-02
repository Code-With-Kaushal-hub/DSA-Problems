class Solution {
public:
    vector<vector<string>> ans;
    void solve(int col,int n,vector<string>temp,vector<int>left,vector<int> upleft,vector<int> downleft){
        if(col==n){
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++){
            if(left[row]!=1&& upleft[row+col]!=1&&downleft[row - col + n - 1]!=1){
                left[row]=1;
                upleft[row+col]=1;
                downleft[row - col + n - 1]=1;
                temp[row][col]='Q';
                solve(col+1,n,temp,left,upleft,downleft);
                temp[row][col]='.';
                left[row]=0;
                upleft[row+col]=0;
                downleft[row - col + n - 1]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
         vector<string> temp(n, string(n, '.'));
         vector<int> left(n,0);
         vector<int> upleft(2*n-1,0);
         vector<int> downleft(2*n-1,0);
         solve(0,n,temp,left,upleft,downleft);
         return ans;

        
    }
};