class Solution {
public:
    string smallestPalindrome(string s) {
        /*
    palindrome consists of three parts:
            first half in lexicographical order
            the sole single letter
            reverse the first half
            store letter in map, <char the letter, int the number of
    appearances>, constdcut a string with half of appearnaces, if know it is a
        */
        int n = s.size(), j = 0; 
        int freq[26]{};

        // traverse the first half 
        for (int i = 0; i < n >> 1; i++) {
            freq[(s[i] & 31) - 1]++;
        }

        for (int i = 0; i < 26; i++) {
            while (freq[i]--) {
                s[j] = 'a' + i; 
                s[n - 1 - j++] = 'a' + i;
            }
        }
        return s;
    }
};