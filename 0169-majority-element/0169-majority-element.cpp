class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = -1;
        sort(nums.begin(), nums.end());
        return nums[ceil(nums.size() / 2)];
    }
};