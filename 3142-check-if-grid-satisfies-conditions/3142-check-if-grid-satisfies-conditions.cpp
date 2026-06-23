class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        // check every element in the [row - 1, col - 1] 2D grid
        // loop left to right, up to down
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                // check if cell violate those two conditions
                if (row < grid.size() - 1) {
                    if ((grid[row][col] == grid[row + 1][col]) == false) {
                        return false;
                    } 
                }
                if (col < grid[0].size() - 1) {
                    if ((grid[row][col] != grid[row][col + 1]) == false) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};