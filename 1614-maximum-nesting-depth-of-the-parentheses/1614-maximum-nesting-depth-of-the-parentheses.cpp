class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int curr_depth = 0;
        for (char ch: s) {
             if (ch == '(') {
                curr_depth++;
                // cout << "current depth is " << curr_depth << endl;
            }
            else if (ch == ')') {
                // update, verify
                max_depth = max(max_depth, curr_depth);
                curr_depth--;
            }
        }
        return max_depth;
    }
};