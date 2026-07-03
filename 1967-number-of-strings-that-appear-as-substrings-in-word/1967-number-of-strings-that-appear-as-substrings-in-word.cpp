class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int sub_str = 0; 
        for (string word_: patterns) {
            if (word.contains(word_) == true) {
                sub_str++;
            }
        }
        return sub_str;
    }
};