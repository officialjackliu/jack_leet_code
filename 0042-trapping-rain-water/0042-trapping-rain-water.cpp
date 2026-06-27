class Solution {
public:
    int trap(vector<int>& height) {
        /*
            refer to question 11, different area compute method
            define water: min (left and right pointer height) at each level or height and all pointers between these two points are lower 
            calculate the whole area, then subtract the up hill height 
            define approach: two pointers, same direction, trigger based O(n^2)
        */
        int left = 0; 
        int right = height.size() - 1; 
        int left_max = height[left];
        int right_max = height[right]; 
        int water_area = 0;
        while (left < right) {
            if (left_max < right_max) {
                left++; 
                left_max = max(left_max, height[left]);
                water_area += left_max - height[left];
            } else if (left_max >= right_max) {
                right--; 
                right_max = max(right_max, height[right]);
                water_area += right_max - height[right];
            }
        }
        return water_area; 
    }
};