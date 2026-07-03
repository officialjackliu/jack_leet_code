class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // use a hashset? 
        unordered_map<char, int> sub_str; 
        int left_ptr = 0; 
        int longest_substr = 0;
        int i = 0;
        for (; i < s.size(); i++) {
            // duplicate value, update key's last seen position and substr length, 
            // new left_ptr position should starts at the element after the duplicated value 
            if (sub_str.count(s[i]) == 1 && i > left_ptr) {
                
                longest_substr = max(longest_substr, i - left_ptr); 
                // cout << "right pointer is at " << i << "    " << s[i] << "      left pointer is at " << left_ptr << "   " << s[left_ptr] << "     longest_substr  "<<  longest_substr << endl;
                left_ptr = max(left_ptr, sub_str[s[i]] + 1);
                sub_str[s[i]] = i; 
                
            } else {
                // not a duplicate, insert the value 
                sub_str[s[i]] = i;
            }
        }
        // make a final update 
        longest_substr = max(longest_substr, i- left_ptr);
        // cout << "right pointer is at " << i << "    " << s[i] << "      left pointer is at " << left_ptr << "   " << s[left_ptr] << "     longest_substr  "<<  longest_substr << endl;
        return longest_substr;
    }
};