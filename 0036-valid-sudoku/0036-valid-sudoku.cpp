class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // is there a way to check all 3 rules together at once 
        // preallocate 3 vectors, each size of 9, row, col, board 
        // whenever seen a number, find its align row, column and board, check if those vectors contain a identical value (check for duplicates). If they do, return false
        unordered_set<int> rows[9];
        unordered_set<int> columns[9];
        unordered_set<int> boards[9]; 
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board.size(); col++) {
                if (board[row][col] != '.') {
                    int num = board[row][col] - '0'; 
                    int row_posi = row; 
                    int col_posi = col; 
                    int board_posi = row /3 * 3 + col / 3; 
                    // cout << "num is " << num << "   row position is " << row_posi << "  column position is " << col_posi << "   board_posi is " << board_posi << endl;
                    if (rows[row_posi].count(num) != 0 || columns[col_posi].count(num) != 0 || boards[board_posi].count(num) != 0) {
                        return false;
                    } else {
                        rows[row_posi].insert(num);
                        columns[col_posi].insert(num);
                        boards[board_posi].insert(num);
                    } 
                }
            }
        }
        return true; 
    }
};