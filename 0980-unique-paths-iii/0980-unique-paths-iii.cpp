class Solution {
public:
// Online C++ compiler to run C++ program online

vector<int> nr={0,1,-1,0};
vector<int> nc={1,0,0,-1};
int sti,stj,endi,endj,obsi,obsj,total=0;
int fun(int n,int m,int i,int j,vector<vector<int>>&vis,int count){
        if(i==endi&&j==endj){
            if(count==total){
            return 1;}
            return 0;
        }
       
        int sum=0;
        vis[i][j]=3;
        for(int k=0;k<4;k++){
            int row=i+nr[k];
            int col=j+nc[k];
            if(row>=0&&row<n&&col>=0&&col<m&&vis[row][col]!=3&&vis[row][col]!=-1){
                
                sum+=fun(n,m,row,col,vis,count+1);
            }
            
        }
        vis[i][j]=0;
        return sum;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    sti=i;
                    stj=j;
                }
                if(grid[i][j]==2){
                    endi=i;
                    endj=j;
                }
                if (grid[i][j] != -1) {
                    total++;
                }
                
            }
        }
        
        return fun(n,m,sti,stj,grid,1);
    }
};