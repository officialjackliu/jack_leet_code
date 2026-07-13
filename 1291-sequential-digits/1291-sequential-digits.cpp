#include <ranges>
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // brute force approach, manually enter all sequential number and return the filtered list by [low, high] constraint
        vector<int> seq_digits = {12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789};
        // special cases: high < seq_digits, low > seq_digits
        if (high < seq_digits[0] || low > seq_digits[seq_digits.size() - 1]) {
            return {};
        }
        int start = 0, end = 0; 
        for (int i = 0; i < seq_digits.size(); i++) {
            // check low condition 
            if (seq_digits[i] >= low) {
                start = i; 
                break;
            }
            // check high condition
        }
        for (int i = seq_digits.size() - 1; i >= 0; i--) {
            if (seq_digits[i] <= high) {
                end = i; 
                break;
            }
        }
        
        return vector<int>(seq_digits.begin() + start, seq_digits.begin() + end+ 1);
    }
};