class Solution {
public:
    int calculate(string s) {
        int index = 0;
        return calc_recur(s, index);
    }

    long long calc_recur(string& s, int& i) {
        // solve using the recursion approach, recurse in function whenever a
        // parenthesis appear
        // '+' & '-' only, no * no /
        long long sum = 0;
        long long num = 0;
        int sign = 1;
        while (i < s.size()) {
            if (isspace(s[i]) != 0) {
                continue;
            }
            // extract nunber
            if (isdigit(s[i]) != 0) {
                num = num * 10 + (s[i] - '0');
            }
            // detect sign, calculate previous accumulative variable, reset num
            else if (s[i] == '-') {
                sum += sign * num;
                num = 0;
                sign = -1;
            } else if (s[i] == '+') {
                sum += sign * num;
                num = 0;
                sign = 1;
            }
            // parentheses, priority calculation, calcualte and shift index
            // using recursion
            else if (s[i] == '(') {
                i++;
                num = calc_recur(s, i);
            } else if (s[i] == ')') {
                sum += sign * num;
                return sum;
            }
            // increment
            i++;
        }
        sum += sign * num;
        return sum;
    }
};

/*

stack<int> number;
        char sign = '+';
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
                if (sign == '+') {
                    number.push(current_num);
                }
                else if (sign == '-') {
                    number.push(-current_num);
                } else if (sign == '*') {
                    int last_num = number.top();
                    number.pop();
                    number.push(last_num * current_num);
                } else if (sign == '/') {
                    int last_num = number.top();
                    number.pop();
                    number.push(last_num / current_num);
                }
            }
            // character is = - operation, record and do the computation later
            else if (ch == '+') {
                sign = '+';

            }
            else if (ch == '-') {
                sign = '-';

            }
            // character is a '*' get the next number immediately and save the
computed number else if (ch == '*') { sign = '*';
            }
            else if (ch == '/') {
                sign = '/';
            }
        }
        // do the final computation, + & - only
        while (number.empty() == false) {
           calc += number.top();
           number.pop();
        }
        return calc;
*/