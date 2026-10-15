class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            set<int> distinct_vals;
            for (int j = i; j < nums.size(); j++) {
                distinct_vals.insert(nums[j]);
                sum += pow(distinct_vals.size(), 2);
            }
        }
        return sum;
    }
};