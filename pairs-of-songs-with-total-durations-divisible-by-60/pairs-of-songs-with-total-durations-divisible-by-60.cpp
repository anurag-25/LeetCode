class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector <int> freq (60, 0);
        for (int &t: time) freq[t%60]++;
        
        int ans = 0;
        ans += freq[0]*(freq[0]-1);
        ans += freq[30]*(freq[30]-1);
        ans /= 2;
        int freqs[60] = {}, res = 0;
        for (int i=1; i<30; i++) ans += freq[i]*freq[60-i];
       
        return ans;
    }
};