class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int j = 0;
        while (j < n / 2) {
            for (int i = j; i < n-1-j; i++) {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[n - 1 - i][j];
                matrix[n - 1 - i][j] = matrix[n - 1-j][n - 1 - i];
                matrix[n - 1-j][n - 1 - i] = matrix[i][n - 1-j];
                matrix[i][n - 1-j] = temp;
            }
            j++;
        }
    }
};