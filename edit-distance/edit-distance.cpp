int edit (string &A, string &B, vector <vector<int>>&dp, int i, int j)    {
    if (i==0) return j;
    if (j==0) return i;
    if (dp[i][j] != -1) return dp[i][j];

    if (A[i-1] == B[j-1]) return dp[i][j] = edit (A, B, dp, i-1, j-1);
     return dp[i][j] = 1+ min ({edit (A, B, dp, i-1, j), edit (A, B, dp, i, j-1), edit (A,B, dp, i-1, j-1)});
}


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector <vector<int>> dp (m+1, vector<int> (n+1,-1));
        return edit (word1, word2, dp, m, n);
    }
};