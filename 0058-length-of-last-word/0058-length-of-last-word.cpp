class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            // cout << "at index   " <<  i << "    word is " << s[i]<< "  start is " << start << endl;
            if (isalpha(s[i]) != 0 && start == -1) {
                // start tracking the "last" word, the index of the final character in the last word 
                start = i;
            } else if (start != -1 && isalpha(s[i]) == 0) {
                // at one element past the final word, compute the length of last word
                return start - i;
            }
        }
        return start + 1;
    }
};