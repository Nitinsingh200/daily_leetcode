class Solution {
public:
// int fun(vector<int>& prices,int n, int i, int k){
//     if( i==n)
//     return 0;
//     if(k==0)
//     return 0;
//     if(k==2){
//         int c1= fun(prices,n,i+1,k-1)-prices[i];
//         int c2 = fun(prices,n,i+1,k);
//         return  max(c1,c2);
//     }
//         else{
//             int c1=fun(prices,n,i+1,k-1)+prices[i];
//             int c2 = fun(prices,n,i+1,k);
//         return  max(c1,c2);


//         }

// }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        
        vector<vector<int>> dp(n + 1);
        for (int i = 0; i <= n; i++) {   
            vector<int> t(3, 0);
            dp[i] = t;
        }

 

                for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 2; k++) {

                if (k == 2) {
                    int c1 = dp[i + 1][k - 1] - prices[i];
                    int c2 = dp[i + 1][k];
                    dp[i][k] = max(c1, c2);
                }
                else {
                    int c1 = dp[i + 1][k - 1] + prices[i];
                    int c2 = dp[i + 1][k];
                    dp[i][k] = max(c1, c2);
                }
            }
        }

        return dp[0][2];
    }
};

        // int a = prices.size();
        // int k=2;
        // int gain = fun(prices,a,0,k);
        // return gain;
 