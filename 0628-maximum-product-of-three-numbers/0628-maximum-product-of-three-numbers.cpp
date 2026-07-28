class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // mog code 
        ranges::sort(nums);
        return max( 
            nums.back() * nums[nums.size() - 2] * nums[nums.size() - 3], 
            nums.back() * nums.front() * nums[1]
        );
    }
};