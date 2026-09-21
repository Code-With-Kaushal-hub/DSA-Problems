class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> arr(n,vector<int>(n, 0));
       
        for(int i=0;i<n;i++){
            int k=rowShift[i];
            for(int j=0;j<n;j++){
                arr[i][j]=grid[i][(j+k)%n];
            }
        }
        for(int i=0;i<n;i++){
            int k=colShift[i];
            for(int j=0;j<n;j++){
                grid[j][i]=arr[(j+k)%n][i];
            }
        }
        return grid;
    }
};