#include <cstdlib> 
class Solution {
public:
    int calculate(string s) {
        stack<int> number; 
        char last_sign = '+';
        int calc = 0; 
        int current_num = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            // skip if character is a space
            if (isspace(ch) != 0) {
                continue;
            }
            // character is a number, push
            else if (isdigit(ch) != 0) {
                current_num = 0; 
                while (i < s.size() && isdigit(s[i]) != 0) {
                    current_num = (current_num * 10) + (s[i] - '0');
                    i++;
                }
                i--;
                if (last_sign == '+') {
                    number.push(current_num);
                }
                else if (last_sign == '-') {
                    number.push(-current_num);
                } else if (last_sign == '*') {
                    int last_num = number.top();
                    number.pop();
                    number.push(last_num * current_num); 
                } else if (last_sign == '/') {
                    int last_num = number.top();
                    number.pop();
                    number.push(last_num / current_num); 
                }
            }
            // character is = - operation, record and do the computation later
            else if (ch == '+') {
                last_sign = '+';
                
            }
            else if (ch == '-') {
                last_sign = '-';
                
            }
            // character is a '*' get the next number immediately and save the computed number
            else if (ch == '*') {
                last_sign = '*';
            }
            else if (ch == '/') {
                last_sign = '/';
            }
        }
        // do the final computation, + & - only 
        while (number.empty() == false) {
           calc += number.top();
           number.pop();
        }
        return calc;
    }
};