class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
int n = prices.size();

        
        vector<vector<int>> dp(n + 1);
        for (int i = 0; i <= n; i++) {   
            vector<int> t(2*k+1, 0);
            dp[i] = t;
        }

 
      for (int i = n - 1; i >= 0; i--) {

            for (int op = 1; op <= 2 * k; op++) {

                if (op % 2 == 0) {  
                    int c1 = dp[i + 1][op - 1] - prices[i];
                    int c2 = dp[i + 1][op];

                    dp[i][op] = max(c1, c2);
                }
                else {  // Sell
                    int c1 = dp[i + 1][op - 1] + prices[i];
                    int c2 = dp[i + 1][op];

                    dp[i][op] = max(c1, c2);
                }
            }
        }

        return dp[0][2 * k];
    }
};