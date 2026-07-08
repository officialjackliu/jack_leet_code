class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*
        matrix traversal pattern: top left to right, goes down, goes right, goes
        u, no overlap or revist every traversal shrink four sides boundary, top,
        down, left right each by opne
        */
        // base case, 1 element
        if (matrix.size() == 1 && matrix[0].size() == 1) {
            return matrix[0];
        }
        int top = 0, bottom = matrix.size() - 1, left = 0,
            right = matrix[0].size() - 1;
        vector<int> spiral;
        while (top <= bottom && left <= right) {
            //cout << "top is " << top << "   bottom is " << bottom << " left is "
                // << left << "  right is " << right << endl;
            // trav top
            for (int top_col = left; top_col <= right; top_col++) {
                spiral.push_back(matrix[top][top_col]);
                //cout << "in top_col, we have pushed back "
                    // << matrix[top][top_col] << endl;
            }
            // trav right
            for (int right_row = top + 1; right_row <= bottom; right_row++) {
                spiral.push_back(matrix[right_row][right]);
                //cout << "in right_row, we have pushed back "
                     //<< matrix[right_row][right] << endl;
            }
            // trav bottom
            if (top < bottom) {
                for (int bottom_col = right - 1; bottom_col >= left;
                     bottom_col--) {
                    spiral.push_back(matrix[bottom][bottom_col]);
                    //cout << "in bottom_col, we have pushed back "
                         //<< matrix[bottom][bottom_col] << endl;
                }
            }

            // trav left
            if (left < right) {
                for (int left_row = bottom - 1; left_row >= top + 1;
                     left_row--) {
                    spiral.push_back(matrix[left_row][left]);
                    //cout << "in left_row, we have pushed back "
                         //<< matrix[left_row][left] << endl;
                }
            }

            // increment
            top++;
            // special case: top and bottom gap is one and left over final top
            // traversal, odd number case if (top + 1 == bottom) {
            //     for (int top_col = left+1; top_col <= right - 1; top_col++) {
            //         spiral.push_back(matrix[top][top_col]);
            //     }
            // }
            bottom--;
            left++;
            right--;
        }
        return spiral;
    }
};