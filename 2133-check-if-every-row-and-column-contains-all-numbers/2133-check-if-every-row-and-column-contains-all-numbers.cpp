class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // rows
        for(int i = 0; i < n; i++) {
            vector<int> arr(n, 0);
            for(int j = 0; j < n; j++) {
                int idx = matrix[i][j] - 1;
                if(arr[idx] != 0) return false;
                arr[idx]++;
            }
        }

        // col
        for(int i = 0; i < n; i++) {
            // one col
            vector<int> arr(n, 0);
            for(int j = 0; j < n; j++) {
                int idx = matrix[j][i] - 1;
                if(arr[idx] != 0) return false;
                arr[idx]++;
            }
        }

        return true;
    }
};