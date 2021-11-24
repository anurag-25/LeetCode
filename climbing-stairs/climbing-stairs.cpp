class Solution {
public:
    int climbStairs(int n) {
        if (n==1 || n==2) return n;
        int last = 2, second_last = 1, curr=0;
        for (int i=3; i<=n; i++) {
            curr = last+second_last;
            second_last = last;
            last = curr;
        }
        return curr;
    }
};