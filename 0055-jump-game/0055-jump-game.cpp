class Solution {
public:
    bool canJump(vector<int>& nums) {
        // base case 
        if (nums.size() == 1) {
            return true;
        }
        // greedy, compute the furthest points we can jump to every index, 
        int furthest_jump = nums[0]; 

        for (int i = 1; i < nums.size(); i++) {
            // can not jump to the current index, stuck 
            if (furthest_jump < i) {
                return false;
            }
            furthest_jump = max(furthest_jump, i + nums[i]);
        }


        if (furthest_jump >= nums.size() - 1) {
            return true;
        } else {
            return false; 
        }
    }
};