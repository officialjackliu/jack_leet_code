#include <stack>
#include <vector> 
#include <iostream> 
#include <sstream>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // reverse operation like a stack, add up evaluate values until we see an operants, pop and build it backl 
        /*
            
        */
        
        stack<int> stack_num;
        stack<string> stack_op;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                int num = 0;
                stringstream ss(tokens[i]);
                ss >> num;
                stack_num.push(num);
            } else if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int first = stack_num.top(); stack_num.pop();
                int second = stack_num.top(); stack_num.pop();
                int val = 0; 
                if (tokens[i] == "+") {
                    val = second + first;
                } else if (tokens[i] == "-") {
                    val = second - first;
                } else if (tokens[i] == "*") {
                    val = second * first;
                } else {
                    val = second / first; 
                }
                stack_num.push(val);
            }
        }
        return stack_num.top();
    }
};
        //          int val_one = stack_.pop(); 
        //         while (stack_.empty() == false) {
        //             int val_two = stack_.pop();
        //         }
        //         if (tokens[i] == '+') {
        //             sum = sum + (val_one + val_two);
        //         } else if (tokens[i] == '-') {
        //             sum = sum + (val_one - val_two);
        //         } else if (tokens[i] == '/') {
        //             sum = sum + (val_one / val_two);
        //         } else if (tokens[i] == '*') {
        //             sum = sum + (val_one * val_two);
        //         }
