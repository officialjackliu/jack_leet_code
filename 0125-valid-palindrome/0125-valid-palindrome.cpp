class Solution {
public:
    bool isPalindrome(string s) {
        // clean string lower char only 
        string palindrome; 
        for (char ch: s) {
            if (isalpha(ch) != 0) {
                palindrome += tolower(ch);
            }
            else if (isdigit(ch) != 0) {
                palindrome += ch;
            }
        }
        // check palindrome, point back and forward: run 2 * O(n), O(n) space
        int left = 0; 
        int right = palindrome.size() -1;
        while (left <= right) {
            if (palindrome[left] != palindrome[right]) {
                return false;
            }
            left++; 
            right--;
        }
        return true;
    }
};