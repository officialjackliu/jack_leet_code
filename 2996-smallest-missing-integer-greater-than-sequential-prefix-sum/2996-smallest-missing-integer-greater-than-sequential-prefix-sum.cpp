class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // find the sequntial numbers 
        // use unordered_set 's count function to find missing value 
        unordered_set<int> num_set; 
        int sum = nums[0];
        num_set.insert(nums[0]);
        // only check consecutive number starting immediately from nums[0]
        // Only check consecutive numbers starting immediately from index 1!
        int i = 1;
        while (i < nums.size() && nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            i++;
        }

        // Insert the rest of the numbers into the set for the missing value check
        while (i < nums.size()) {
            num_set.insert(nums[i]);
            i++;
        }
        // iterate from sps to find the missing value 
        int missing_val = sum; 
        while (num_set.count(missing_val) != 0) {
            missing_val++;
        }
        return missing_val;
    }
};