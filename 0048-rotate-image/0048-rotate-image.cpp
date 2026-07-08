class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
            rotate 90 degree, i row represents number. oflayers to rotate, 1 way swap, top left -> top right -> bottom right -> bottom left -> top left 
        */
        int n = matrix.size(), k = n - 1; 
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < k - i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[k - j][i];
                matrix[k - j][i] = matrix[k - j][i];
                matrix[k - j][i] = matrix[k - i][k - j];
                matrix[k - i][k - j] = matrix[j][k - i];
                matrix[j][k - i] = temp;
            }
        }
    }
};