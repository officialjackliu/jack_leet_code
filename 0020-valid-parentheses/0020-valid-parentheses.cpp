class Solution {
public:
    bool isValid(string s) {
        // use stack to store open brackets, validate close brackets 
        stack<char> open_bracket;
        for (char ch: s) {
            // store in stack if ch is a open brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                open_bracket.push(ch);
            }
            // ch is a close bracket, check if most recent open bracket align with the close bracket 
            else {
                if (open_bracket.empty() == true) {
                    return false;
                }
                else if (ch == ')' && open_bracket.top() == '(') {
                    open_bracket.pop();
                }
                else if (ch == '}' && open_bracket.top() == '{') {
                    open_bracket.pop();
                }
                else if (ch == ']' && open_bracket.top() == '[') {
                    open_bracket.pop();
                } else {
                    return false;
                }
            } 
        }
        return (open_bracket.empty() == true) ? true : false;
    }
};