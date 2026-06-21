class Solution {
public:
    bool isAnagram(string s, string t) {
        // one hashmap, one loop 
        if (s.length() != t.length()) {
            return false; 
        }
        map<char, int> hash_map; 
        for (char ch: s) {
            hash_map[ch]++;
        }
        for (char ch: t) {
            if (hash_map.find(ch) == hash_map.end() || hash_map[ch] == 0) {
                return false;
            }
            hash_map[ch] = hash_map[ch] - 1;
        }
        return true;
    }
};