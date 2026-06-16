class Solution {
public:
    string processStr(string s) {
        // read from left to right, adhere the input output rule 
        string str;
        for (char ch: s) {
            if (ch == '*') {
                // removes 
                if (str.empty() == false && isalpha(str.back()) != 0) {
                    str.pop_back();
                }
            } else if (ch == '#') {
                // duplicates 
                str += str;
            } else if (ch == '%') {
                // reverse the current result
                reverse(str.begin(), str.end());
            } else {
                // regular english character, append it 
                str += ch;
            }
        }
        return str;
    }
};