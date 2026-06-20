class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // store pair of char in pattern match with a word with string, if a new varation pair appear, return false
        // strip words in s and store them in vector 
        vector<string> s_vec; 
        int s_start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isspace(s[i]) != 0) {
                s_vec.push_back(s.substr(s_start, i-s_start));
                s_start = i+1;
            }
        }
        
        // push the last word 
        s_vec.push_back(s.substr(s_start, s.size()-s_start));
        if (pattern.size() != s_vec.size()) {
            return false;
        }
        unordered_map<char, string> pat_map; 
        unordered_map<string, char> s_map; 
        s_start = 0;
        
        for (char ch: pattern) {
            // push a new char, check if the aligned word is also new
            if (pat_map.find(ch) == pat_map.end()) {
                pat_map[ch] = s_vec[s_start];
            }
            if (s_map.find(s_vec[s_start]) == s_map.end()) {
                s_map[s_vec[s_start]] = ch;
            }
            if (s_map[s_vec[s_start]] != ch || pat_map[ch] != s_vec[s_start]) {
                return false;
            }
            s_start++;
        }
        return true;
    }
};