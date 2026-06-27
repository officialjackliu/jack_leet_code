class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window technique, left right starts at 0, window slide left once left to right hits the target, once find the a satisfed window, move the "window or the range "
        int left = 0;
        int right = 0; 
        int current_sum = 0; 
        int min_elem = INT_MAX; 
        for (; right < nums.size(); right++) {
            current_sum += nums[right]; 
            while (current_sum >= target) {
                // update the size of subarray (sliding window) 
                min_elem = min(min_elem, right - left + 1); 
                current_sum -= nums[left]; 
                left++; 
            }
        }
        return (min_elem == INT_MAX)? 0 : min_elem; 
    }
};