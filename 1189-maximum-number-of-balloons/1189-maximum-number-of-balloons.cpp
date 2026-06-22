class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // ballon: 1 b, 1 a, 2 l, 1 o, 1 n 
        // a hash table to count instance of those letters in text, satisfy the requirement 
        unordered_map<char, int> ballon_map; 
        for (char ch: text) {
            if (ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n') {
                ballon_map[ch]++;
            }
        }
        // rule, find min of (b, a, l, n) and l has to be at least twice as large as that min number 
        return min({ballon_map['b'], ballon_map['a'],  ballon_map['n'], ballon_map['o'] / 2, ballon_map['l'] / 2});
        
    }
};