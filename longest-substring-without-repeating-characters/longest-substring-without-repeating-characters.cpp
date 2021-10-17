class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> m;
        int left=0, right=0, mx = 0;
        while (right<s.length() ) {
            m[s[right]]++;
            
            if (m[s[right]] == 1) {
                mx = max (mx, right-left+1);
            }
            while (m[s[right]] > 1) {
                m[s[left]]--;
                left++;
            }
            right++;
        }
        return mx;
    }
};