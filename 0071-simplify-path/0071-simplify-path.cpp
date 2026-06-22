

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string dir;
        
        // 1. Split the path by '/' and process left-to-right
        while (getline(ss, dir, '/')) {
            
            // Ignore empty strings (caused by "//") and current directory (".")
            if (dir == "" || dir == ".") {
                continue;
            }
            
            // Go up a level if we see ".."
            if (dir == "..") {
                if (!stack.empty()) {
                    stack.pop_back(); // Safely remove the previous directory
                }
            } 
            // Otherwise, it's a valid directory name! Push it to the stack.
            else {
                stack.push_back(dir);
            }
        }
        
        // 2. Rebuild the final canonical path from the stack
        string result = "";
        for (const string& s : stack) {
            result += "/" + s;
        }
        
        // 3. Edge Case: If we popped everything (e.g., "/../"), return the root "/"
        return result.empty() ? "/" : result;
    }
};