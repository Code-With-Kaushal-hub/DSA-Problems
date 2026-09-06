class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<int> prow={0,0,1,-1};
        vector<int> pcol={1,-1,0,0};
        int pre=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(q.size()>0){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            image[row][col]=color;
            for(int i=0;i<4;i++){
                int nr=row+prow[i];
                int nc=col+pcol[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m){
                    if(vis[nr][nc]==0&&image[nr][nc]==pre){
                        
                        image[nr][nc]=color;
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }

        }
        return image;
    }
};