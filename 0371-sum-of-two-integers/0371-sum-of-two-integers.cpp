class Solution {
public:
    int getSum(int a, int b) {
        // keep tracking two things carry on AND the digit value 
        // carry on use & and << to track two 1 s case and shift num, 
        // add is XOR as carry as two 1 flip digit to 0, 
        // repetively do this until carry on is gone 
        while (b != 0) {
            int carry = (a & b) << 1; 
            a = a ^ b; 
            b = carry;
        }
        return a;
    }
};