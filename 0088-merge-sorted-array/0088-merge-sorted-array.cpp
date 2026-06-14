class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(nums1.size(), 0);
        int one = m - 1, two = n - 1; 
        for (int i = temp.size() - 1; i >= 0; i--) {
            // nums1 is completed, only take values from nums2 
            if (one < 0) {
                temp[i] = nums2[two--];
            }
            // nums2 is completed, only take vlaues from nums1
            else if (two < 0) {
                temp[i] = nums1[one--];
            } else {
                temp[i] = (nums1[one] < nums2[two]) ? nums2[two--] : nums1[one--];
            }
            
        }
        nums1 = temp; 
        return;
    }
};