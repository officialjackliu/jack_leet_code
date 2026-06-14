class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, unique1 = 0, unique2 = 0; 
        bool fill_second = true;
        nums[unique1] = nums[i++];
        for (; i < nums.size(); i++) {
            // cout << "at index " << i << endl;
            // assign first appearance, brand new element
            if (nums[i] != nums[unique1]) {
                // unique1 = unique1 + 1
                
                nums[++unique1] = nums[i];
                // cout << "assign  " <<  nums[i] << "  first appearnce at index  " << unique1<< endl;
                fill_second = true;
            }
            // assign second appearance
            else if (nums[i] == nums[unique1] && fill_second == true) {
                nums[++unique1] = nums[i];
                // cout << "assign  " <<  nums[i] << "  second appearnce at index  " << unique1<< endl;
                fill_second = false;
            }
        }
        return unique1 + 1;
    }
};