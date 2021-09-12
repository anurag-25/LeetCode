class Solution {
public:
    void printLevels (vector<vector<int>> &ans, int numRows, int currRow) {
        if (currRow==numRows) return;
        vector <int> v;
        v.push_back (1);
        
        for (int i=0; i< ans[currRow-1].size()-1; i++) v.push_back (ans[currRow-1][i] + ans[currRow-1][i+1]);
        
        v.push_back (1);
        ans.push_back (v);
        printLevels (ans, numRows, currRow+1);
    }
    
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> ans;
        vector <int> v1 (1, 1);
        ans.push_back (v1);
        if (numRows == 1) return ans;
        vector <int> v2 (2,1);
        ans.push_back (v2);
        printLevels (ans, numRows, 2);
        return ans;
    }
};