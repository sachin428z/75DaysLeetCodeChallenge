class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // n+2 to safely handle ind+2 (cooldown skip)
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit;
                if (buy == 0)  // can buy
                    profit = max(dp[ind+1][0],           // skip
                                -prices[ind] + dp[ind+1][1]); // buy
                if (buy == 1)  // holding, can sell
                    profit = max(dp[ind+1][1],           // skip
                                 prices[ind] + dp[ind+2][0]); // sell + cooldown
                dp[ind][buy] = profit;
            }
        }
        return dp[0][0];
    }
};