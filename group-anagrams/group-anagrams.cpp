class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> m;
        
        for (int i=0; i<strs.size(); i++) {
            string s = strs[i];
            sort (strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto it = m.begin(); it!=m.end(); it++) {
            ans.push_back ((*it).second);
        }
        return ans;
    }
};