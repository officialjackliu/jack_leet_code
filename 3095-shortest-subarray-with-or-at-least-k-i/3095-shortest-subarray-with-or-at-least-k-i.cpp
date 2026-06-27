class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        // brute force, avoid the complicated bit-wise manipulations
        int min_sub_arr = INT_MAX; 
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int or_val = nums[i];
            for (int j = i; j < n; j++) {
                or_val = or_val | nums[j];
                if (or_val >= k) {
                    min_sub_arr = min(min_sub_arr, j - i + 1);
                }
            }
        }
        return (min_sub_arr == INT_MAX) ? -1 : min_sub_arr; 
    }
};