class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // two pointer approach, vector of pairs, first is nums value, second is original index 
        vector<pair<int, int>> num_map; 
        for (int i = 0; i < nums.size(); i++) {
            num_map.push_back({nums[i], i});
        }
        sort(num_map.begin(), num_map.end());
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int sum = num_map[left].first + num_map[right].first; 
            if (sum == target) {
                break;
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
        return {num_map[left].second, num_map[right].second}; 
    }
};