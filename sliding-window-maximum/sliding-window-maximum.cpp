class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> heap;
        int i=0, j=0;
        vector<int> ans;
        while (j<nums.size()) {
            // if (heap.empty() ) heap.insert (nums[j]);
            while (!heap.empty() && heap.back()<nums[j]) {
                heap.pop_back();
            }
            heap.push_back(nums[j]);
            
            if (j-i+1 == k) {
                ans.push_back (heap.front());
                if (nums[i] == heap.front()) heap.pop_front();
                i++;
            }
            j++;
        }
        return ans;
    }
};