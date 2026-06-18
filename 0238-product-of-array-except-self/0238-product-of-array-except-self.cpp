class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int num_size = nums.size();
        // left side 
        vector<int> left_vec;
        left_vec.reserve(num_size);
        int left_product = 1;
        for (int i = 0; i < num_size; i++) {
            left_vec[i] = left_product;
             
            // techinically shouldn't push back for the last element 
            left_product *= nums[i];
           
        }
        // right side 
        vector<int> right_vec;
        right_vec.reserve(num_size);
        int right_product = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            // cout << "right product at " << i << "index is " << right_product << endl;
            right_vec[i] = right_product;
            // techinically shouldn't push back for the last element 
            right_product *= nums[i];
        }
        // total 
        vector<int> total_product_vec;
        total_product_vec.reserve(num_size);
        for (int i = 0; i < num_size; i++) {
            cout << "left product at " << i << "index is " << left_vec[i]  << endl;
            cout << "right product at " << i << "index is " << right_vec[i]  << endl;
            total_product_vec.push_back(left_vec[i] * right_vec[i]);
        }
        return total_product_vec;
    }
};