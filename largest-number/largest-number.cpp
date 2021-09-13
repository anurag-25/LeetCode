class Solution {
public:
    static bool comp (string a, string b) {
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector <string> v;
        for (int x: nums) v.push_back (to_string(x));
        sort (v.begin(), v.end(), comp);
        
        string ans = "";
        for (string s: v) ans+= s;
        int i=0;
        while (i<ans.length()-1) {
            if (ans[i]=='0') i++;
            else break;
        }
        if (i>0) ans.erase (0, i);
        return ans;
    }
};