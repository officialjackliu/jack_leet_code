class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // anagram strings consist of same set of letters, use a set to store anagram, 
        // sorted str & index of those anagram
        unordered_map<string, vector<string>> anagrams; 
        for (int i = 0; i < strs.size(); i++) {
            string sorted_word = strs[i];
            sort(sorted_word.begin(), sorted_word.end());
            anagrams[sorted_word].push_back(strs[i]);
        }
        vector<vector<string>> grouped_anagrams;
        for (const auto& [key, value]: anagrams) {
            grouped_anagrams.push_back(value);
        }
        return grouped_anagrams;
    }
};