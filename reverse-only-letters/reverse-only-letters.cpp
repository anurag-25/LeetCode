class Solution {
public:
    bool isValid (char &c) {
        return (c>='a' && c <='z') || (c>='A' && c<='Z');
    }
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.length()-1;
        // for (int i=0; i<s.length()/2; i++) {
        while (i<j) {
            while (!isValid (s[i]) && i<j) i++;
            while (!isValid (s[j]) && i<j) j--;
            swap (s[i++], s[j--]);
        }
        return s;
    }
};