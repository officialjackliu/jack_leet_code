class Solution {
public: 

    int jump(vector<int>& nums) {
        // base case 
        if (nums.size() == 1 ) {
            return 0; 
        }
        // greedy
        int jump = 1; 
        int furthest_jump = nums[0];
        int jump_bound = nums[0];
        if (jump_bound >= nums.size() - 1) {
            return 1;
        }
        if (jump_bound >= nums.size() - 1) {
            return jump;
        }
        for (int i = 1; i < nums.size(); i++) {
           // cout << "at index " << i << " made decision to ";
           furthest_jump = max(furthest_jump, i + nums[i]);
           if (i == jump_bound) {
                ++jump;
                jump_bound = furthest_jump; 
                // cout << "complete one jump bound, we have jump" << jump <<" time" << "  the new bound is " << jump_bound<< endl; 
                if (jump_bound >= nums.size() - 1) {
                    break;
                }
           } 
        }   
        return jump;
    }
};