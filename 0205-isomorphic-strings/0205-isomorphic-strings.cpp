class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> s_map; 
        unordered_map<char, int> t_map; 
        for (int i = 0; i < s.size(); i++) {
            // insert s char to s_map if it does not exist
            if (s_map.find(s[i]) == s_map.end()) {
                s_map[s[i]] = i;
            }
            // do for t 
            if (t_map.find(t[i]) == t_map.end()) {
                t_map[t[i]] = i;
            }
            // check if two string are isomoprhic order of there character appearance are same 
            if (t_map[t[i]] != s_map[s[i]]) {
                return false;
            }
        }
        return true;
    }
};