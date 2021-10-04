class Solution {
public:
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector <int> dp (amount+1, amount+1);   // since max number of coins can be = amount
    //     dp[0] = 0;
    //     for (int i=1; i<=amount; i++) {
    //         for (int j=0; j<n; j++) {
    //             if (coins[j] <= i) 
    //                 dp[i] = min (dp[i], dp[i-coins[j]]+1);
    //         }
    //     }
    //     if (dp[amount]>amount) return -1;
    //     return dp[amount];
    // }
    
    int solve (vector<int>& coins, int amount, int n, vector <vector<int>>& dp) {
        if (amount == 0) return 0;
        if (n ==0) return INT_MAX-1;
        if (dp[n][amount] != -1) return dp[n][amount];
        if (coins[n-1] <= amount) {
            return dp[n][amount] = min (solve(coins,amount,n-1,dp), solve(coins,amount-coins[n-1],n,dp)+1);
        }
        else return dp[n][amount] = solve(coins,amount,n-1,dp);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector <vector<int>> dp (n+1, vector <int> (amount+1, -1));
        int ans = solve (coins, amount, n, dp);
        if (ans >= INT_MAX-1) return -1;
        return ans;
    }
};