class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hash map approach, nums[i], target-nums[i]
        unordered_map<int, int> numMap; 
        // int n = nums.size(); 
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; 
            if (numMap.count(complement) != 0) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};