class Solution {
public:
    int fun(vector<int>& cost, int i, vector<int>&dp) {
        if (i >= cost.size()) {
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        dp[i]=cost[i] + min(fun(cost, i + 1,dp),
                             fun(cost, i + 2,dp));
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(fun(cost, 0,dp), fun(cost, 1,dp));
    }
};