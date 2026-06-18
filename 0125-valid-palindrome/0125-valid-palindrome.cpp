class Solution {
public:
    bool isPalindrome(string s) {
        // O(1) space, 1 time O(n) run 
        int left = 0; 
        int right = s.size() -1;
        while (left < right) {
            // left not alphanumerical, skip
            cout << "s[left]:   " << s[left] << "   s[right]:  " << s[right]<<  endl;
            if (isalnum(s[left]) == 0) {
                left++;
                continue;
            }
            // right not alphanumerical, skip
            if (isalnum(s[right]) == 0) {
                right--;
                continue;
            }
            // pointer check, alpha and number
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            // pass increment
            left++;
            right--;
        }
        return true;
    }
};