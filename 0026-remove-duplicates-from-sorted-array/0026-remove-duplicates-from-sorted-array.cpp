class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0, i = 0; 
        nums[index] = nums[i]; 
        //cout << "nums.size() is " << nums.size() << endl;
        for (i = 1; i < nums.size(); i++) {
            // new value, adds to nums
            // cout << "at index " << i << endl;  
            if (nums[i] != nums[index]) {
                //cout << "find non duplicate value   " << nums[i] << "   nums[index]" << nums[index];  
                nums[++index] = nums[i];
                //cout << "++index is     " <<  index << endl;
            }
        }
        return index + 1;
    }
};