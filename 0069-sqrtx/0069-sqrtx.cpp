class Solution {
public:
    int sqrt_recur(int low, int high, int x) {
        int mid = (low + high) / 2;
        long long mid_squ = (long long) mid * mid; 
        long long ans = x;
        if (mid_squ == ans) {
            return mid;
        }
        else if (mid_squ > ans) {
            return sqrt_recur(low, mid, x);
        }
        else if (mid_squ < ans) {
            if (mid == low) {
                return low;
            }
            return sqrt_recur(mid, high, x);
        }
        return 1;
    }

    int mySqrt(int x) {
        // how to determine cases where x's sqrt is a decimal
         if (x == 1) {
            return x;
        }
        int high = x; 
        int low = 0; 
        return sqrt_recur(low, high, x);        
    }
};