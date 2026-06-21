class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // one pass, record seens value and index in a map, if a duplicate,
        // check index distance such (i - j) <= k return true
        unordered_map<int, int> seen_val;
        for (int i = 0; i < nums.size(); i++) {
            // check for duplicate values
            if (seen_val.find(nums[i]) != seen_val.end() &&
                (i - seen_val[nums[i]] <= k)) {
                // within the k range, return true
                // cout << "duplicate value is " << nums[i] << "   second val
                // index is " << i << " first index is " << seen_val[nums[i]] <<
                // "  k is " << k << endl;

                return true;

                // not of k range, update the most recent seen index
                // seen_val[nums[i]] = i;
            } else {
                seen_val[nums[i]] = i;
            }
            // if (seen_val.find(nums[i]) == seen_val.end()) {

            // }
        }
        return false;
    }
};