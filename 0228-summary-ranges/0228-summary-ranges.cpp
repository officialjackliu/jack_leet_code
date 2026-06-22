class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty() == true || nums.size() == 0) {
            return {};
        }
        if (nums.size() == 1) {
            return {to_string(nums[0])};
        }
        int start = 0, end = 0;
        vector<string> vec_str;
        int i = 1;
        for (; i < nums.size(); i++) {
            // streaks is broken, move start
            if (nums[i] != nums[i - 1] + 1) {
                if (start == end) {
                    vec_str.push_back(to_string(nums[start]));
                } else {
                    vec_str.push_back(to_string(nums[start]) + "->" +
                                      to_string(nums[end]));
                }
                start = i, end = i;
            }
            // increment streak, move end
            else {
                end = i;
            }
        }
        // add the last sequence range

        if (start == end) {
            vec_str.push_back(to_string(nums[start]));
        } else {
            vec_str.push_back(to_string(nums[start]) + "->" +
                              to_string(nums[end]));
        }
        start = i, end = i;

        return vec_str;
    }
};