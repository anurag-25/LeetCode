class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector <vector<bool>> dp (n, vector<bool> (n,false));
        // dp (i,j) ->substring starting at ith index and ending at jth index
        for (int i=0; i<n; i++) dp[i][i] = true;
        int startIndex =0, length = 1;
        for (int i=0; i<n-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                startIndex = i;
                length = 2;
            }
        }
        
        for (int lenOfSubstring = 3; lenOfSubstring <=n; lenOfSubstring++) {
            for (int i=0; i<n-lenOfSubstring+1; i++) {
                int j = i + lenOfSubstring - 1;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if (lenOfSubstring> length) {
                        startIndex = i;
                        length = lenOfSubstring;
                    }
                }
            }
        }
        return s.substr (startIndex, length);
    }
};