class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        for (int i=1; i<strs.size(); ++i)   {
            if (strs[i].size() < s.size()) s.erase(strs[i].size());
            for (int j=0; j<strs[i].size(); j++)    {
                if (strs[i][j] != s[j]) {
                    s.erase(j);
                    break;
                }
            }
        }
        return s;
    }
};