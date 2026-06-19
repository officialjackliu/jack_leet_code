class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> two_sum(2);
        int left_ptr = 0, right_ptr = numbers.size() -1;
        while (left_ptr < right_ptr) {
            // found pointers for two sum element
            int sum = numbers[left_ptr] + numbers[right_ptr];
            if (sum == target) {
                break;
            }
            else if (sum > target) {
                right_ptr--;
            } else if (sum < target) {
                left_ptr++;
            }
        }
        two_sum[0] = left_ptr + 1;
        two_sum[1] = right_ptr + 1;
        return two_sum;
    }
};