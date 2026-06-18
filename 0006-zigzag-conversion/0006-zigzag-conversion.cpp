class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> vec(numRows);
        string zigzag;
        int col = 0;
        int str_num = s.size();
        while (s.empty() == false) {
            // assign row with a character
            for (int i = 0; i < numRows; i++) {
                if (s.empty() == true) {
                    break;
                }
                // remove the character
                vec[i].push_back(s.front());
                s.erase(0, 1);
            }
            // assign diagonal
            for (int i = numRows - 2; i > 0; i--) {
                if (s.empty() == true) {
                    break;
                }
                // remove the character
                vec[i].push_back(s.front());
                s.erase(0, 1);
            }
        }
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < vec[row].size(); col++) {
                zigzag += vec[row][col];
           }
        }

        return zigzag;
    }
};