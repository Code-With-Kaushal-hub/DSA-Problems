
class Solution {
public:
    int fun(vector<vector<int>>& obstacleGrid, int row, int col,
            int n, int m, vector<vector<int>>& dp) {

        if(row >= n || col >= m)
            return 0;

        if(obstacleGrid[row][col] == 1)
            return 0;

        if(row == n-1 && col == m-1)
            return 1;

        if(dp[row][col] != -1)
            return dp[row][col];

        return dp[row][col] =
            fun(obstacleGrid, row, col+1, n, m, dp) +
            fun(obstacleGrid, row+1, col, n, m, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return fun(obstacleGrid, 0, 0, n, m, dp);
    }
};
