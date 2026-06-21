class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        // sort nums
        sort(nums.begin(), nums.end());
        int LCS = 0;
        int current_streak = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            // streak is kept
            if (nums[i + 1] == nums[i] + 1) {
                current_streak++;
            }
            // duplicate value
            if (nums[i + 1] == nums[i]) {
                continue;
            }
            // streak broken
            else if (nums[i + 1] - nums[i] != 1) {
                LCS = max(LCS, current_streak);
                current_streak = 0;
            }
        }
        LCS = max(LCS, current_streak);
        // return (LCS > 0) ? LCS + 1 : LCS ;
        return LCS + 1;
    }
};