class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // traverse the 2D grid in outer bound on 0s , inner use BFS and queue to visit near by islands 1s, BSF only occur when we traverse on an island

        int islandCounts = 0; 
        int row_size = grid.size();
        int col_size = grid[0].size();
        // ONLY track visited islands 
        vector<vector<bool>> visited(row_size, vector<bool>(col_size, false));
        // coordinate: up right down left, {row, col}
        vector<pair<int, int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int row = 0; row < row_size; row++) {
            for (int col = 0; col < col_size; col++) {
                // trigger bfs when land an unvisited island
                if (grid[row][col] == '1' && visited[row][col] == false) {
                    // cout << "land on unvisited land " << row << "   " << col << endl;
                    queue<pair<int, int>> q;
                    islandCounts++;
                    q.push({row, col});
                    visited[row][col] = true;
                    while (q.empty() == false) {
                        pair<int, int> coordinate = q.front();
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            int row_pos = coordinate.first + moves[i].first;
                            int col_pos = coordinate.second + moves[i].second;
                            // push the new coordinate onto the queue if it pass 
                            // 4 bounds conditions, check if it is an island, check whether visited
                            if (row_pos >= 0 && row_pos < row_size && col_pos >= 0 && col_pos < col_size && grid[row_pos][col_pos] == '1' && visited[row_pos][col_pos] == false) {
                                visited[row_pos][col_pos] = true;
                                q.push({row_pos, col_pos});
                                // cout << "       going to visit land" << row_pos << "   " << col_pos << endl;
                            }
                        }
                    }
                }
            }
        }

        return islandCounts;
    }
};