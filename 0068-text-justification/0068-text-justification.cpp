class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        /*
            rules: 
            1. fit as many word[i] in a fixed size max_width letter, do not add word[i+1] if adding the word will overflow the max_wdith word[i+1].size() + 1 (1 space)
            2. when a word is added, insert from left to right, minimum one char of white space between two words, try to distributed those space as evenly as possible, the leftover space should start pushing from left side first, even the remaining space should be on the right hand side of the final word in a line 
            3. last line, if multiple words, only 1 space between those words, remaining space goes on the right 
        */
        vector<string> result;      // the final array of formatted lines  
        vector<string> line;        // temporary array to hold words for the current line 
        int length = 0;             // track the raw number of letters in the current line 
        int i = 0;                  // pointer for our words array 

        while (i < words.size()) {
            // PHASE 1: Grouping, length = raw letters, line.size() represents the minimum 1 space needed between words 
            // if condition represent the adding the current word will exceed the max_width, organize words store in line into 
            if (length + line.size() + words[i].size() > maxWidth) {
                // PHASE 2: SPACE MATH
                int extra_space = maxWidth - length; 

                int gaps = max(1, (int)line.size() - 1);
                int spaces_per_gap = extra_space / gaps; 
                int remainders = extra_space % gaps; 

                // PHASE 3: ASSEMBLY 
                // distribute extra_space evenly in the gaps, add remainders to left most gap iteratively, one for each left to right 
                for (int j = 0; j < gaps; j++) {
                    line[j] += string(spaces_per_gap, ' ');
                    if (remainders > 0) {
                        line[j] += ' ';
                        remainders--;
                    }
                }
                // construct the line then add it to the result 
                string curr_line = "";
                for (string word: line) {
                    curr_line += word;
                }
                result.push_back(curr_line);

                // reset the temporary tracker for the next line
                line.clear();
                length = 0; 
            }
            line.push_back(words[i]);
            length += words[i].size(); 
            i++;
        }

        //  final line, the length of word would never trigger the MaxLength exceed case 
        string last_line = ""; 
        for (int k = 0; k < line.size(); k++) {
            last_line += line[k]; 
            if (k < line.size() - 1) {
                last_line += ' ';
            }
        }
        int trail_space = maxWidth - last_line.size();
        result.push_back(last_line + string(trail_space, ' '));
        return result; 
    }
};