class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_elem = *max_element(nums.begin(), nums.end());
        int added = 0; 
        for (int num: nums) {
            added += max_elem - num;
        }
        return added;
    }
};