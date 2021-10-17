class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string (num);        
        int start = -1, end = -1, max = s.length()-1;

        for (int i=s.length()-1; i>=0; i--) {
            if (s[i] > s[max]) max = i;
            if (s[i] < s[max]) {
                start = i;
                end = max;
            }
        }
        if (start != -1) swap (s[start], s[end]);
        return stoi (s);
    }
};