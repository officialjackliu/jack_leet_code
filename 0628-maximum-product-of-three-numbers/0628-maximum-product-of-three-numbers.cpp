class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // negative values make the problem difficult to solve
        // two negative > take one small positive
        sort(nums.begin(), nums.end());
        int one, two, three;
        int n = nums.size();
        // vector does not contain negative, straightforward or // full negative case
        cout << "nums[0] is " << nums[0] << endl;
        if (nums[0] >= 0 || nums[n-1] < 0) {
            three = nums[n - 1];
            two = nums[n - 2];
            one = nums[n - 3];
        } 
        // partial negative
        else if (nums[n-1] >= 0 && nums[0] < 0) {
            three = nums[n - 1];
            // case 1: take two negative because product of two negative number
            // is greater than product of two positive
            if (nums[0] * nums[1] > nums[n - 2] * nums[n - 3]) {
                two = nums[1];
                one = nums[0];
            }
            // case 2 still take positive
            else {
                two = nums[n - 2];
                one = nums[n - 3];
            }
        }
        
        cout << "one is " << one << endl;
        cout << "two is " << two << endl;
        cout << "three is " << three << endl;
        return one * two * three;
    }
};