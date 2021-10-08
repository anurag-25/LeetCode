class Solution {
public:
    void reverse (vector<int>& nums) {
        for (int i=0; i< nums.size()/2; i++) swap (nums[i], nums[nums.size()-1-i]);
        return;
    }
    void rotate(vector<int>& nums, int k) {
        reverse (nums);

        int n = nums.size();
        k = k%n;
        
        for (int i=0; i<k/2; ++i) {
            swap (nums[i], nums[k-1-i]);
        }
        for (int i=0; i<(n-k)/2; i++) {
            swap (nums[k+i], nums[n-1-i]);
        }
        return;
    }
};

/* Method-1
    int n = nums.size();
    k = k%n;
    vector<int> rev (k);
    for (int i=n-k, j=0; i<n; i++, j++) {
        rev[j] = nums[i];
    }
    for (int i=0; i<n-k; i++) {
        nums[n-1-i] = nums[n-1-i-k];
    }
    for (int i=0; i<k; i++) nums[i] = rev[i];
    return;
*/

/* Method-2
        int n = nums.size();
        for (int i=0; i<k%n; i++) {
            int currNum = nums[n-1];
            for (int i=n-1; i>0; i--) nums[i] = nums[i-1];
            nums[0] = currNum;
        }
        return;      
*/