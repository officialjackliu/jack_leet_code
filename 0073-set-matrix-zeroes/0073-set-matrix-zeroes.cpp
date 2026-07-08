class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
            find all 0 elements coordinate in the matrix,
            iterate row by row, record columsn and rows need to be set to 0, fill those rows with 0 after the scan loop
        */

        unordered_set<int> rows;
        unordered_set<int> columns;
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[0].size(); col++) {
                if (matrix[row][col] == 0) {
                    rows.insert(row);
                    columns.insert(col);
                }
            }
        }
        // fill rows
        for (int row: rows) {
            fill(matrix[row].begin(), matrix[row].end(), 0);
        }
        // fill columns
        for (int col: columns) {
            for (int row = 0; row < matrix.size(); row++) {
                matrix[row][col] = 0;
            }
        }
        return;
    }
};

// // prefill row 0
// for (int col = 0; col < matrix[0].size(); col++) {
//     if (matrix[0][col] == 0) {
//         columns.insert(col);
//         // fill column
//         for (int row = 0; row < matrix.size(); row++) {
//             matrix[row][col] = 0;
//         }
//     }
// }
// // fill row
// if (columns.empty() == false) {
//     fill(matrix[0].begin(), matrix[0].end(), 0);
// }
// // fill rest of rows and columns
// for (int row = 1; row < matrix.size(); row++) {
//     bool fill_row = false;
//     for (int col = 0; col < matrix[0].size(); col++) {
//         // skip filled column
//         if (columns.count(col) == 1) {
//             continue;
//         }
//         if (matrix[row][col] == 0) {
//             // needs fill row
//             fill_row = true;
//             columns.insert(col);
//             for (int row = 0; row < matrix.size(); row++) {
//                 matrix[row][col] = 0;
//             }
//         }
//     }
//     if (fill_row == true) {
//         fill(matrix[row].begin(), matrix[row].end(), 0);
//     }