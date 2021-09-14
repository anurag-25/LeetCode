class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map <int, unordered_set<int>> user_minutes;
        for (vector<int> entry: logs) {
            user_minutes[entry[0]].insert(entry[1]);
        }
        // for (auto p: user_minutes) {
        //     cout << p.first << "->";
        //     for (auto mins: p.second) {
        //         cout << mins << ',';
        //     }
        //     cout << endl;
        // }
        
        vector <int> ans (k);
        for (auto p: user_minutes) {        //p = pair <int, set<int> >
            ans[p.second.size()-1]++;
        }
        return ans;
    }
};