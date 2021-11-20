class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> freq;
        int nonZero = 0;
        for (char &c: t) {
            if (freq.find(c)==freq.end() ) nonZero++;
            freq[c]++;
        }
        int left = 0, length = INT_MAX, i=0, j=0;
        while (j<s.size() ) {
            if (freq.find(s[j]) != freq.end() ) {
                freq[s[j]]--;
                if (freq[s[j]] == 0) nonZero--;
            }
            while (nonZero==0) {
                if (j-i+1 < length) {
                    left = i, length = j-i+1;
                }
                if (freq.find(s[i]) != freq.end()) {
                    freq[s[i]]++;
                    if (freq[s[i]]==1) nonZero++;
                }
                i++;
            }
            j++;
        }
        if (length==INT_MAX) return "";
        else return s.substr(left, length);
    }
};