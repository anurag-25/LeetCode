class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) return 0;
        unordered_set <int> s (nums.begin(), nums.end());
        int ans =1;
        for (int &n: nums) {
            if (s.find(n-1) != s.end()) continue;
            int next = n+1;
            while (s.find(next) != s.end()) {
                ans = max (ans, next-n+1);
                next++;
            }
        }
        return ans;
    }
};