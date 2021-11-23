class Solution {
    vector<string> mobile {"","", "abc", "def",
                          "ghi", "jkl", "mno",
                          "pqrs", "tuv", "wxyz" };
    
public:
    void solve (string digits, vector<string> &ans, string curr, int idx) {
        if (idx==digits.size()) {
            ans.push_back (curr);
            return;
        }
        int keyNumber = digits[idx] - '0';
        for (int i=0; i<mobile[keyNumber].size(); i++ ) {
            solve (digits, ans, curr+mobile[keyNumber][i], idx+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length()==0) return ans;
        string curr = "";
        solve (digits, ans, curr, 0);
        return ans;
    }
};