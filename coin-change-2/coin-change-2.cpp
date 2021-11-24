class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp (amount+1, 0);
        dp[0] = 1;
        for (int i=0; i<coins.size(); i++) {
            for (int j=coins[i]; j<=amount; j++) {
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};


// int change(int amount, vector<int>& coins) {
//     int n = coins.size();
//     vector<vector<int>> dp (n+1, vector<int>(amount+1, 0));
//     for (int i=0; i<=n; i++) dp[i][0] = 1;
//     for (int i=1; i<=n; i++) {
//         for (int j=1; j<=amount; j++) {
//             if (coins[i-1] <= j) dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
//             else dp[i][j] = dp[i-1][j];
//         }
//     }
//     return dp[n][amount];
// }