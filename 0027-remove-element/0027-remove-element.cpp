class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // use two pointer technique: trigger based pointer, i to iterate nums, index tirgger poistion of elem != val 
        int index = 0, i = 0; 
        for (; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};