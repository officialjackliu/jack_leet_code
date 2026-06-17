class Solution {
public:
    char processStr(string s, long long k) {
        // two linear passes expects with O(1) space O(n) runtime 
        // compute the modified string length 
        long long len = 0; 
        for (char ch: s) {
            if (ch == '*') {
                if (len > 0) {
                    len--;
                }
            }
            else if (ch == '#') {
                len *= 2; 
            }
            else if (ch == '%') {
                continue;
            } else {
                len++;
            }
        }
        if (k >= len) {
            return '.';
        }
        // reverse engineer the "imagined" modified result string to find the kth character in the original string
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if (c == '*') {
                len++;
            }
            else if (c == '#') {
                long long half = len / 2; 
                if (k >= half) {
                    k -= half;
                }
                len = half;
            }
            else if (c == '%') {
                k = len - 1 - k;
            }
            else {
                // find the element
                if (k == len -1) {
                    return c;
                }
                len--;
            }
        }
        return '.';
    }
};