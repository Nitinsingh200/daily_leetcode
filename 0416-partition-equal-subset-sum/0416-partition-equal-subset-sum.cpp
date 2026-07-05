class Solution {
public:
    bool canPartition(vector<int>& nums) {
          int n = nums.size();

        int totalSum = 0;
        for (int x : nums)
            totalSum += x;

        if (totalSum % 2 == 1)
            return false;

        int sum = totalSum / 2;

        int i, j;
              vector<vector<int>> dp(n + 1);

        for (int i = 0; i <= n; i++) {
            vector<int> t(sum + 1, 0);
            dp[i] = t;
        }

        // Base case
        dp[n][0] = 1;
        
        for( int i=n-1;i>=0; i-- ){
            for(int j=0; j<=sum; j++){
                if(nums[i]>j){
                    dp[i][j]=dp[i+1][j];
                    
                }else{
                    dp[i][j]= dp[i+1][j-nums[i]] || dp[i+1][j];

                }
            }
        }
        return dp[0][sum];

    }
};