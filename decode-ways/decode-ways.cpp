class Solution {
public:
    int numDecodings(string s) {
        vector <int> dp (s.length()+1, 0);
        dp[0] = 1;
        if (s[0] != '0') dp[1] = 1;
        for (int i=1; i<s.length(); i++) {
            string num = "";
            num += s[i];
            if (stoi(num)>0) dp[i+1] += dp[i];
            num = "";
            num += s[i-1];
            num +=s[i];
            int x = stoi(num);
            if (x <=26 && x>=10) dp[i+1] += dp[i-1];
        }
        return dp[s.length()];
    }
};