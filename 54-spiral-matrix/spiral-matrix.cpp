class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        int i = 0;
        int j = 0;
        vector<int> result;
        while (true) {
            for (int k = j; k < width; k++) {
                result.push_back(matrix[i][k]);
            }
            i++;
            if (i >= height)
                break;
            for (int l = i; l < height; l++) {
                result.push_back(matrix[l][width - 1]);
            }
            width--;
            if (j >= width)
                break;
            for (int k = width - 1; k >= j; k--) {
                result.push_back(matrix[height - 1][k]);
            }
            height--;
            if (i >= height)
                break;

            for (int l = height - 1; l >= i; l--) {
                result.push_back(matrix[l][j]);
            }
            j++;
            if (j >= width)
                break;
        }

        return result;
    }
};