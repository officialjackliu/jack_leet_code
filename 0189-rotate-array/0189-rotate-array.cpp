class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // parallel pointers solution with O(1) space
        int rotate = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + rotate);
        reverse(nums.begin() + rotate, nums.end());
        return;
    }
};