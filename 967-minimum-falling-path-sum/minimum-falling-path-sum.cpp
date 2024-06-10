class Solution {
public:
    // int helper(int i, int j, int& n, vector<vector<int>>& matrix,
    //            vector<vector<int>>& dp) {
    //     if (j < 0 || j >= n)
    //         return 1e9;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (i == 0)
    //         return dp[i][j] = matrix[i][j];
        
    //     return dp[i][j] =
    //                matrix[i][j] + min(min(helper(i - 1, j - 1, n, matrix, dp),
    //                                       helper(i - 1, j, n, matrix, dp)),
    //                                   helper(i - 1, j + 1, n, matrix, dp));
    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     int ans = 1e9;
    //     vector<vector<int>> dp(n, vector<int>(n, -1));
    //     for (int i = 0; i < n; i++) {
    //         ans = min(ans, helper(n - 1, i, n, matrix, dp));
    //     }
    //     return ans;
    // }

    // tabulation
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0), cur(n, 0);
        for(int i=0;i<n;i++){
            prev[i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                cur[j] = matrix[i][j] + prev[j];
                if(j>0){
                    cur[j] = min(cur[j],  matrix[i][j] + prev[j-1]);
                }
                if(j<n-1){
                    cur[j] = min(cur[j],  matrix[i][j] + prev[j+1]);
                }
            }
            prev = cur;
        }
        int ans = 1e9;
        for(int i=0;i<n;i++){
            ans = min(ans, prev[i]);
        }
        return ans;
    }
    
};