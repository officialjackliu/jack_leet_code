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
        if (s.size() == 1) {
            return s;
        }
        map<char, int> words;
        for (char ch : s) {
            words[ch]++;
        }
        string first = "";
        char ch = 'A';
        for (const auto& kv : words) {
            // single letter case
            if (kv.second % 2 == 1) {
                first.append(kv.second / 2, kv.first);
                ch = kv.first;
            } else {
                first.append(kv.second / 2, kv.first);
            }
        }
        string second = first;
        reverse(second.begin(), second.end());

        return (ch == 'A') ? first + second : first + ch + second;
    }
};