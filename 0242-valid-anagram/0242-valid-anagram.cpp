class Solution {
public:
    bool isAnagram(string s, string t) {
        // base case
        if (s.size() != t.size()) {
            return false;
        }
        map<char, int> s_map;
        map<char, int> t_map;
        for (char ch : s) {
            s_map[ch]++;
        }
        for (char ch : t) {
            t_map[ch]++;
        }
        if (s_map.size() != t_map.size()) {
            return false;
        }
        auto s_it = s_map.begin();
        auto t_it = t_map.begin();
        for (; s_it != s_map.end() && t_it != t_map.end(); s_it++ , t_it++) {

            if (s_it->first != t_it->first || s_it->second != t_it->second) {
                return false;
            }
        }
        return true;
    }
};