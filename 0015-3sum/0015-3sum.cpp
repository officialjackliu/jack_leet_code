class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> three_sum;
        // sort the vector
        sort(nums.begin(), nums.end());
        // element value <-[pair with]-> index positions of the element (where
        // it appear) unordered_map<int, vector<int>> map; for (int i = 0; i <
        // nums.size(); i++) {
        //     // auto it = map.find(nums[i]);
        //     //  key exist! insert the element's new psotiion
        //     // if (it != map.end()) {
        //     map[nums[i]].push_back(i);
        //     //}
        // }
        int left = 0, mid = 0, right = 0;
        for (; left < nums.size() - 2; left++) {
            if (left > 0 && nums[left] == nums[left-1]) {
                continue;
            }
            mid = left + 1;
            right = nums.size() - 1;
            while (mid < right) {
                int sum = nums[left] + nums[mid] + nums[right];
                if (sum == 0) {
                    three_sum.push_back({nums[left], nums[mid], nums[right]});
                    mid++;
                    while (nums[mid] == nums[mid - 1] && mid < right) {
                        mid++;
                    }
                } else if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    mid++; // needs to shift left pointer, this collection of
                           // values is to small, increase the minimum value
                }
            }
        }
        return three_sum;
    }
};