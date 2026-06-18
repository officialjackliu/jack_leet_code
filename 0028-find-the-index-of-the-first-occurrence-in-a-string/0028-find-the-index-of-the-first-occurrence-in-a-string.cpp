class Solution {
public:
    int strStr(string haystack, string needle) {
        int sub_start = 0; 
        int sub_size = needle.size(); 
        while (sub_start + sub_size <= haystack.length()) {
            if (haystack.substr(sub_start, sub_size) == needle) {
                return sub_start;
            }
            sub_start++;
        }
        return -1; 
    }  
};