class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /*
            do it with out of place algorithm first,
            create an new empty board to assign the new state, assign old board
           to be the new board, iterate through the old board in double for
           loop, use a helper function to determine its boundary and rule to
           follow and assign state, assign the new value on the cell to the new
           board
        */
        vector<vector<int>> new_board(board.size(),
                                      vector<int>(board[0].size(), 0));
        vector<int> row_posi = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> col_posi = {-1, 0, 1, -1, 1, -1, 0, 1};
        int board_height = board.size() - 1;
            int board_width = board[0].size() - 1;
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                int neighbors = 0;
                bool live_cell =
                    (board[row][col] == 1) ? true : false;
                for (int i = 0; i < row_posi.size(); i++) {
                    int neigh_row = row + row_posi[i];
                    int neigh_col = col + col_posi[i];
                    // skip out of bound neighbor
                    if (neigh_row < 0 || neigh_row > board_height ||
                        neigh_col < 0 || neigh_col > board_width) {
                        continue;
                    }
                    // count neighbor
                    if (board[neigh_row][neigh_col] == 1) {
                        neighbors++;
                    }
                }
                // executes rules
                // 1,2,3
                if (live_cell == true && (neighbors < 2 || neighbors > 3)) {
                    new_board[row][col] = 0;
                }
                else if (live_cell == false && neighbors == 3) {
                    new_board[row][col] = 1;
                }
                else {
                    new_board[row][col] = board[row][col];
                }
            }
        }
        board = new_board;
        
    }
};
