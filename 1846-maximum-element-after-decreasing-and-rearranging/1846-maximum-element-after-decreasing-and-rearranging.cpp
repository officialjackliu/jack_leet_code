class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        /*
            rearrange arr in 2 ways 
            1. reduce value of arr[i] to a smaller positive value; can not increase the value of arr[i]; 
            2. rearrange the position of element 

            rules: 
            1. arr[0] == 1
            2. diff between two adjacent element <= 1, 

            approach: sort the element, set arr[0] = 1, accomodate elements in a ascending order

        */
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i-1] > 1) {
                arr[i] = arr[i-1] + 1;
            }
        }
        return arr.back();
    }
};