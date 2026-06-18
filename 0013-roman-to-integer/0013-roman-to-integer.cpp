class Solution {
public:
    unordered_map<char, int> numerals = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    
    bool index_check(int index, string str) {
        if (str[index] == 'I' && (str[index + 1] == 'V' || str[index + 1] == 'X')) {
            return true;
        } else if (str[index] == 'X' && (str[index + 1] == 'L' || str[index + 1] == 'C')) {
            return true;
        } else if (str[index] == 'C' && (str[index + 1] == 'D' || str[index + 1] == 'M')) {
            return true;
        } else {
            return false;
        }
    }
    
    int romanToInt(string s) {
        // check the instance
        int roman_int = 0; 
        for (int i = 0; i < s.size(); ) {
            // special case 
            if (index_check(i, s) == true && i <= s.size() - 2) {
                roman_int += numerals[s[i + 1]] -  numerals[s[i]];
                i += 2;
            } else {
                // not special
                roman_int += numerals[s[i]];
                i += 1;
            }
        }
        return roman_int;
    }
};