class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // given a vector, that contain a rnage of values, find missing values in that range 
        // use an unordered_set approach, iterate from min to max, elements that are not contain in the set are issing 
        vector<int> missing_elements;
        int min_elem = INT_MAX; 
        int max_elem = INT_MIN; 
        unordered_set<int> elem_set;
        for (int i = 0; i < nums.size(); i++) {
            elem_set.insert(nums[i]);
            min_elem = min(nums[i], min_elem);
            max_elem = max(nums[i], max_elem);
        }
        // iterate from min to max, find missing elements
        for (int elem = min_elem; elem <= max_elem; elem++) {
            if (elem_set.count(elem) == 0) {
                missing_elements.push_back(elem);
            }
        }
        return missing_elements;
    }
};