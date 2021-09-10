class Solution {
public:
    
    void solve (int open, int close, vector <string> &ans, string op) {
        if (open==0 && close==0) {
            ans.push_back (op);
            return;
        }
        if (open>0) {
            string op1 = op + '(';
            solve (open-1, close, ans, op1);
        }
        if (close > open) {
            string op1 = op + ')';
            solve (open, close-1, ans, op1);
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector <string> v;
        string op = "";
        int open=n, close=n;
        solve (open, close, v, op);
        return v;
    }
};