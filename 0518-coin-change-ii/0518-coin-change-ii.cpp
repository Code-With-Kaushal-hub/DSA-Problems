
class Solution {
public:
    int fun(vector<int>& coins, int amount, int i,
            vector<vector<int>>& dp) {

        if(amount == 0)
            return 1;

        if(i == coins.size() || amount < 0)
            return 0;

        if(dp[i][amount] != -1)
            return dp[i][amount];

        // Take current coin (can take it again)
        int take = fun(coins, amount-coins[i], i, dp);

        // Not take current coin
        int nottake = fun(coins, amount, i+1, dp);

        return dp[i][amount] = take + nottake;
    }

    int change(int amount, vector<int>& coins) {

        vector<vector<int>> dp(coins.size(),
                               vector<int>(amount+1, -1));

        return fun(coins, amount, 0, dp);
    }
};
