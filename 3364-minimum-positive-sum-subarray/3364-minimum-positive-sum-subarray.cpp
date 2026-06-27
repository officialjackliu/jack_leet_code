class Solution {
public:
    int minSum(vector<int>& nums, int size) {
        // init sliding window 
        int min_sum = INT_MAX;
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
        }
        if (sum > 0) {
            min_sum = sum;
        }
        for (int right = size; right < nums.size(); right++) {
            // slide the window add an element from right delete an element from left
            sum += nums[right]; 
            sum -= nums[right - size];
            if (sum > 0) {
                min_sum = min(min_sum, sum);
            }
        }
        return min_sum;
    }

    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        // find min sum solution for every subarray sized between l and r 
        int min_sum = INT_MAX;
        for (int i = l; i <= r; i++) {
            min_sum = min(min_sum, minSum(nums, i));
        }
        return (min_sum == INT_MAX) ? -1 : min_sum;
    }
};