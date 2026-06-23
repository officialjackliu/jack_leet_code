class Solution {
public:
    string reorderSpaces(string text) {
        // rearrange so space between word are equal and left over space are
        // stored toward the end
        int space = 0;
        vector<string> words;
        string word = "";
        for (int i = 0; i < text.size(); i++) {
            if (isalpha(text[i]) != 0) {
                word += text[i];
            } else {
                // space append space, push back word if it is not resetted
                if (word.empty() == false) {
                    words.push_back(word);
                }
                word = "";
                space++;
            }
        }
        if (word.empty() == false) {
            words.push_back(word);
        }
        // length of each space between words, there are total words.size() - 1
        // space in between words
        string empty_space = "";
        int space_len = 0;
        if (space > 0 && ((words.size() - 1) >= 1)) {
            space_len = space / (words.size() - 1);
            empty_space = string(space_len, ' ');
        }
        string arranged_word;
        // cout << "total " << space << "  white space" << endl;
        // cout << "length of empty space between words is " << space_len <<
        // endl; cout << "length of left over space between words is "
        //      << space % space_len << endl;
        for (int i = 0; i < words.size() - 1; i++) {
            arranged_word += words[i];
            if (empty_space.empty() == false) {
                arranged_word += empty_space;
                space -= space_len; 
            }
        }
        // append last word and left over space
        arranged_word += words[words.size() - 1];
        arranged_word += string(space, ' ');
        return arranged_word;
    }
};