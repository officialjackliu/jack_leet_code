class Solution {
public:
    long long sumAndMultiply(int n) {
        // find all non zero digits in n, sum them, then multiply the original number with that sum 
        int sum = 0; 
        int concate = n; 
        int x = 0; 
        int index = 1;
        while (concate != 0) {
            int digit = concate % 10;
            if (digit != 0) {
                sum += digit; 
                x += digit * index; 
                index *= 10; 
            }
            concate /= 10;
        }
        return static_cast<long long>(x) * static_cast<long long>(sum);
    }
};