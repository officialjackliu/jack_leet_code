class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        // construct prefixGcd + short prefixGcd in non-decreasing order
        vector<int> prefixGcd(nums.size());
        int max_num = 0; 
        for (int i = 0; i < nums.size(); i++) {
            max_num = max(max_num, nums[i]);
            prefixGcd[i] = gcd(nums[i], max_num);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        // take pairs 
        long long gcd_sum = 0; 
        for (int i = 0; i < nums.size() / 2; i++) {
            // compute pairs 
            gcd_sum += (long long) (gcd(prefixGcd[i], prefixGcd[prefixGcd.size() - 1 - i]));            
        }

        return gcd_sum;
    }
};